#include "Physics/PhysicsEngine.h"

void PhysicsEngine::PhysicsUpdate(float deltaTime) 
{
	ClearCollisions();

	for (auto& rigidbody : rigidbodies_)
	{
		if (!rigidbody->IsStatic())
		{
			for (auto& force : forces_)
			{
				rigidbody->AddForce(force);
			}

			rigidbody->SetForce(rigidbody->GetForce() + (gravity_ * rigidbody->GetGravityScale()) * rigidbody->GetMass());

			rigidbody->SetVelocity(rigidbody->GetVelocity() + rigidbody->GetForce() / rigidbody->GetMass() * deltaTime);
			rigidbody->SetPosition(rigidbody->GetPosition() + rigidbody->GetVelocity() * deltaTime);

			rigidbody->GetCollider()->SetCenter(rigidbody->GetPosition());

			rigidbody->SetForce(Vector2(0.0f, 0.0f));

			CheckCollisions(rigidbody);
		}
	}

	//Stops applying forces on the Rigidbodies at the end of the Physics Update
	forces_.clear();
}
void PhysicsEngine::CheckCollisions(Rigidbody* myRigidbody) 
{
	for(const auto& other : rigidbodies_)
	{
		Vector2 mtv;

		if (myRigidbody != other && !CheckCollisionDone(myRigidbody, other)) 
		{
			const auto mySphere = dynamic_cast<SphereCollider*>(myRigidbody->GetCollider());
			auto* otherSphere = dynamic_cast<SphereCollider*>(other->GetCollider());
			if (mySphere != nullptr && otherSphere != nullptr)
			{
				if (SphereCollider::IsOverlappingSphere(mySphere, otherSphere, mtv))
				{
					mySphere->IsColliding(true);
					otherSphere->IsColliding(true);
					mySphere->IsOverlapping(true);
					otherSphere->IsOverlapping(true);

					SolveCollision(myRigidbody, other);
					SolveMTV(myRigidbody, other, mtv);
				}
				else
				{
					mySphere->IsOverlapping(false);
					otherSphere->IsOverlapping(false);
				}
			}
			AddCollision(myRigidbody, other);
		}
	}
	ClearCollisions();
}
void PhysicsEngine::SolveCollision(Rigidbody* myBody, Rigidbody* otherBody) 
{
	const Vector2 v1 = myBody->GetVelocity();
	const Vector2 v2 = otherBody->GetVelocity();

	Vector2 n = Vector2(otherBody->GetPosition() - myBody->GetPosition()).Normalized();
	Vector2 g = n.RightOrtho();

	const float V1n = n.Dot(v1);
	const float V1g = g.Dot(v1);
	const float V2n = n.Dot(v2);
	const float V2g = g.Dot(v2);

	const Vector2 v1AfterImpact = Vector2(n.x * V2n + g.x * V1g, n.y * V2n + g.y * V1g);
	const Vector2 v2AfterImpact = Vector2(n.x * V1n + g.x * V2g, n.y * V1n + g.y * V2g);

	if (!myBody->IsStatic()) 
		myBody->SetVelocity(v1AfterImpact * myBody->GetBounciness());
	else
		otherBody->SetVelocity((v1AfterImpact + (v2AfterImpact * -1.0f) * otherBody->GetBounciness()));

	if (!otherBody->IsStatic()) 
		otherBody->SetVelocity(v2AfterImpact * otherBody->GetBounciness());
	else
		myBody->SetVelocity((v1AfterImpact + (v2AfterImpact * -1.0f)  * myBody->GetBounciness()));
	
}
void PhysicsEngine::SolveMTV(Rigidbody* myBody, Rigidbody* otherBody, Vector2& mtv) 
{
	if (mtv.SqrMagnitude() > 0.0f) 
	{
		if (!myBody->IsStatic())
			myBody->SetPosition(myBody->GetPosition() - (mtv * 0.5f));
		if (!otherBody->IsStatic())
			otherBody->SetPosition(otherBody->GetPosition() + (mtv * 0.5f));
	}
}

void PhysicsEngine::RegisterRigidbody(Rigidbody* rigidbody) 
{
	rigidbodies_.push_back(rigidbody);
}
void PhysicsEngine::RemoveRigidbody(Rigidbody* rigidbody) 
{
	if (!rigidbody) return;
	const auto itr = std::find(rigidbodies_.begin(), rigidbodies_.end(), rigidbody);
	if (itr == rigidbodies_.end()) return;
	rigidbodies_.erase(itr);
}

void PhysicsEngine::AddForce(Vector2 force) 
{
	forces_.emplace_back(force);
}
void PhysicsEngine::SetGravity(Vector2 gravity)
{
	gravity_ = gravity;
}
void PhysicsEngine::SetGravity(float gravity)
{
	gravity_ = Vector2(0.0f, gravity);
}

void PhysicsEngine::AddCollision(Rigidbody* myBody, Rigidbody* otherBody)
{
	if (!CheckCollisionDone(myBody, otherBody)) 
	{
		collisions_.emplace_back(std::pair<Rigidbody*, Rigidbody*>(myBody, otherBody));
	}
}
bool PhysicsEngine::CheckCollisionDone(Rigidbody* myBody, Rigidbody* otherBody) const
{
	for (const auto& pair : collisions_)
	{
		if ((pair.first == myBody && pair.second == otherBody) || (pair.first == otherBody && pair.second == myBody)) 
		{
			return true;
		}
	}
	return false;
}
void PhysicsEngine::ClearCollisions() 
{
	collisions_.clear();
}

void PhysicsEngine::Clear() 
{
	rigidbodies_.clear();
}

Vector2 PhysicsEngine::GetGravity() const
{
	return gravity_;
}
