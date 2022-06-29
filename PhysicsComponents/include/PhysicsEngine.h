#pragma once
#include <vector>
#include "Rigidbody.h"
#include "Vector2.h"
#include "Collider.h"
#include "SphereCollider.h"

class PhysicsEngine 
{
public:

	void PhysicsUpdate(float deltaTime);
	void SolveCollision(Rigidbody*, Rigidbody*);
	void CheckCollisions(Rigidbody*);
	void SolveMTV(Rigidbody*, Rigidbody*, Vector2&);

	void RegisterRigidbody(Rigidbody* rigidbody);
	void RemoveRigidbody(Rigidbody* rigidbody);
	void AddForce(Vector2* force);

private:

	std::vector<Rigidbody*> _rigidbodies;
	std::vector<Vector2*> _forces;

	Vector2 _gravity = Vector2(0.0f, -9.81f);

	std::vector<std::pair<Rigidbody*, Rigidbody*>> _collisions;

	void AddCollision(Rigidbody*, Rigidbody*);
	bool CheckCollisionDone(Rigidbody*, Rigidbody*);
	void ClearCollisions();

};