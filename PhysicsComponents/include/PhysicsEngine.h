#pragma once
#include <vector>
#include "Rigidbody.h"
#include "Vector2.h"

class PhysicsEngine 
{
public:

	void PhysicsUpdate();
	void RegisterRigidbody(Rigidbody* rigidbody);
	//Remove Rigidbody

private:

	std::vector<Rigidbody*> _rigidbodies;
	std::vector<Vector2*> _forces;

};