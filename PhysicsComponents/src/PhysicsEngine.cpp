#include "PhysicsEngine.h"

/// <summary>
/// Updates the physical position of all rigidbodies
/// </summary>
void PhysicsEngine::PhysicsUpdate() 
{
	for (auto& rigidbody : _rigidbodies)
	{
		rigidbody->UpdatePosition();
		std::cout << rigidbody->GetPosition();
	}
}

/// <summary>
/// Register the Rigidbody in the _rigidbodies std::vector
/// </summary>
/// <param name="rigidbody">The rigidbody to register</param>
void PhysicsEngine::RegisterRigidbody(Rigidbody* rigidbody) 
{
	_rigidbodies.emplace_back(rigidbody);
}