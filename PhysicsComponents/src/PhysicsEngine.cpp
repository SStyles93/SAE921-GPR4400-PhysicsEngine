#include "PhysicsEngine.h"

/// <summary>
/// Updates the physical position of all rigidbodies
/// </summary>
void PhysicsEngine::PhysicsUpdate(float deltaTime) 
{
	ClearCollisions();

	for (auto& rigidbody : _rigidbodies)
	{
		for (auto& force : _forces)
		{
			rigidbody->AddForce(force);
		}
		
		rigidbody->SetForce(rigidbody->GetForce() + (_gravity* rigidbody->GetGravityScale()) * rigidbody->GetMass());
		
		rigidbody->SetVelocity(rigidbody->GetVelocity() + rigidbody->GetForce() / rigidbody->GetMass() * deltaTime);
		rigidbody->SetPosition(rigidbody->GetPosition() + rigidbody->GetVelocity() * deltaTime);

		rigidbody->GetCollider()->SetCenter(rigidbody->GetPosition());

		rigidbody->SetForce(Vector2(0.0f, 0.0f));
		
		CheckCollisions(rigidbody);

		//std::cout << rigidbody->GetPosition();
	}
	_forces.clear();
}

/// <summary>
/// Checks the collision between two colliders
/// </summary>
/// <param name="me">The collider to check</param>
/// <param name="other">The other collider with which the first one is checked</param>
void PhysicsEngine::CheckCollisions(Rigidbody* myRigidbody) 
{
	bool isColliding = false;

	for(auto& other : _rigidbodies)
	{
		Vector2 mtv;

		if (myRigidbody != other) 
		{
				SphereCollider* mySphere = dynamic_cast<SphereCollider*>(myRigidbody->GetCollider());
				SphereCollider* otherSphere = dynamic_cast<SphereCollider*>(other->GetCollider());
				if (mySphere != nullptr && otherSphere != nullptr) 
				{
					if (SphereCollider::IsOverlappingSphere(mySphere, otherSphere, mtv))
					{
						mySphere->IsColliding(true);
						//std::cout << "mySphere is colliding" << std::endl;
						SolveCollision(myRigidbody, other);
						SolveMTV(myRigidbody, other, mtv);
					}
					else
					{
						//Not yet (SAT etc...)
					}
				}

				BoxCollider* myBox = dynamic_cast<BoxCollider*>(myRigidbody->GetCollider());
				BoxCollider* otherBox = dynamic_cast<BoxCollider*>(other->GetCollider());
				if (myBox != nullptr && otherBox != nullptr) 
				{
					if (BoxCollider::IsOverlappingBox(myBox, otherBox, mtv))
					{
						myBox->IsColliding(true);
						SolveCollision(myRigidbody, other);
						SolveMTV(myRigidbody, other, mtv);
					}
				}
				
		}
	}
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

	myBody->SetVelocity(v1AfterImpact);
	otherBody->SetVelocity(v2AfterImpact);
}

void PhysicsEngine::SolveMTV(Rigidbody* myBody, Rigidbody* otherBody, Vector2& mtv) 
{
	myBody->SetPosition(myBody->GetPosition() + (mtv * 0.5f));
	myBody->SetPosition(myBody->GetPosition() - (mtv * 0.5f));
}

/// <summary>
/// Register the Rigidbody in the PhysicsEngine
/// </summary>
/// <param name="rigidbody">The Rigidbody to register</param>
void PhysicsEngine::RegisterRigidbody(Rigidbody* rigidbody) 
{
	_rigidbodies.push_back(rigidbody);
}

/// <summary>
/// Removes the Rigidbody from the PhysicsEngine
/// </summary>
/// <param name="rigidbody">The Rigidbody to remove</param>
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
