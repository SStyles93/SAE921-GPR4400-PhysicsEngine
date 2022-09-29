#include "Physics/PhysicsEngine.h"

void PhysicsEngine::PhysicsUpdate(float deltaTime) 
{
	ClearCollisions();

	for (auto& rigidbody : _rigidbodies)
	{
		if (!rigidbody->IsStatic())
		{
			for (auto& force : _forces)
			{
				rigidbody->AddForce(force);
			}

			rigidbody->SetForce(rigidbody->GetForce() + (_gravity * rigidbody->GetGravityScale()) * rigidbody->GetMass());

			rigidbody->SetVelocity(rigidbody->GetVelocity() + rigidbody->GetForce() / rigidbody->GetMass() * deltaTime);
			rigidbody->SetPosition(rigidbody->GetPosition() + rigidbody->GetVelocity() * deltaTime);

			rigidbody->GetCollider()->SetCenter(rigidbody->GetPosition());

			rigidbody->SetForce(Vector2(0.0f, 0.0f));

			CheckCollisions(rigidbody);
		}
	}

	//Stops applying forces on the Rigidbodies at the end of the Physics Update
	_forces.clear();
}
void PhysicsEngine::CheckCollisions(Rigidbody* myRigidbody) 
{
	for(auto& other : _rigidbodies)
	{
		Vector2 mtv;

		if (myRigidbody != other && !CheckCollisionDone(myRigidbody, other)) 
		{
			SphereCollider* mySphere = dynamic_cast<SphereCollider*>(myRigidbody->GetCollider());
			SphereCollider* otherSphere = dynamic_cast<SphereCollider*>(other->GetCollider());
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

			BoxCollider* myBox = dynamic_cast<BoxCollider*>(myRigidbody->GetCollider());
			BoxCollider* otherBox = dynamic_cast<BoxCollider*>(other->GetCollider());
			if (myBox != nullptr && otherBox != nullptr) 
			{
				if (BoxCollider::IsOverlappingBox(myBox, otherBox, mtv))
				{
					myBox->IsColliding(true);
					otherBox->IsColliding(true);
					myBox->IsOverlapping(true);
					otherBox->IsOverlapping(true);

					SolveCollision(myRigidbody, other);
					SolveMTV(myRigidbody, other, mtv);
				}
				else 
				{
					myBox->IsOverlapping(false);
					otherBox->IsOverlapping(false);
				}
			}

			BoxCollider* myBox1 = dynamic_cast<BoxCollider*>(myRigidbody->GetCollider());
			BoxCollider* otherBox1 = dynamic_cast<BoxCollider*>(other->GetCollider());

			SphereCollider* otherSphere1 = dynamic_cast<SphereCollider*>(other->GetCollider());
			SphereCollider* mySphere1 = dynamic_cast<SphereCollider*>(myRigidbody->GetCollider());
			if (myBox1 != nullptr && otherSphere1 != nullptr)
			{
				if (BoxCollider::IsOverlappingSphere(myBox1, otherSphere1, mtv))
				{
					myBox1->IsColliding(true);
					otherSphere1->IsColliding(true);
					myBox1->IsOverlapping(true);
					otherSphere1->IsOverlapping(true);

					SolveCollision(myRigidbody, other);
					SolveMTV(myRigidbody, other, mtv);
				}
				else
				{
					myBox1->IsOverlapping(false);
					otherSphere1->IsOverlapping(false);
				}
			}
			else if (otherBox1 != nullptr && mySphere1 != nullptr)
			{
				if (SphereCollider::IsOverlappingBox(mySphere1, otherBox1, mtv))
				{
					otherBox1->IsColliding(true);
					mySphere1->IsColliding(true);
					otherBox1->IsOverlapping(true);
					mySphere1->IsOverlapping(true);

					SolveCollision(myRigidbody, other);
					SolveMTV(myRigidbody, other, mtv);
				}
				else
				{
					otherBox1->IsOverlapping(false);
					mySphere1->IsOverlapping(false);
				}
			}
			AddCollision(myRigidbody, other);
		}
	}
	ClearCollisions();
}
void PhysicsEngine::SolveCollision(Rigidbody* myBody, Rigidbody* otherBody) 
{
	Vector2 v1 = myBody->GetVelocity();
	Vector2 v2 = otherBody->GetVelocity();

	Vector2 n = Vector2(otherBody->GetPosition() - myBody->GetPosition()).Normalized();
	Vector2 g = n.RightOrtho();

	float V1n, V1g, V2n, V2g;
	V1n = n.Dot(v1);
	V1g = g.Dot(v1);
	V2n = n.Dot(v2);
	V2g = g.Dot(v2);

	Vector2 v1AfterImpact, v2AfterImpact;
	v1AfterImpact = Vector2(n._x * V2n + g._x * V1g, n._y * V2n + g._y * V1g);
	v2AfterImpact = Vector2(n._x * V1n + g._x * V2g, n._y * V1n + g._y * V2g);

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
	_rigidbodies.push_back(rigidbody);
}
void PhysicsEngine::RemoveRigidbody(Rigidbody* rigidbody) 
{
	if (!rigidbody) return;
	auto itr = std::find(_rigidbodies.begin(), _rigidbodies.end(), rigidbody);
	if (itr == _rigidbodies.end()) return;
	_rigidbodies.erase(itr);
}

void PhysicsEngine::AddForce(Vector2 force) 
{
	_forces.emplace_back(force);
}
void PhysicsEngine::SetGravity(Vector2 gravity)
{
	_gravity = gravity;
}
void PhysicsEngine::SetGravity(float gravity)
{
	_gravity = Vector2(0.0f, gravity);
}

void PhysicsEngine::AddCollision(Rigidbody* myBody, Rigidbody* otherBody)
{
	if (!CheckCollisionDone(myBody, otherBody)) 
	{
		_collisions.emplace_back(std::pair<Rigidbody*, Rigidbody*>(myBody, otherBody));
	}
}
bool PhysicsEngine::CheckCollisionDone(Rigidbody* myBody, Rigidbody* otherBody) 
{
	for (auto pair : _collisions)
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
	_collisions.clear();
}

void PhysicsEngine::Clear() 
{
	_rigidbodies.clear();
}

Vector2 PhysicsEngine::GetGravity() 
{
	return _gravity;
}