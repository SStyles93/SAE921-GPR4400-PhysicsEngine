#pragma once
#include <vector>
#include "Rigidbody.h"
#include "Vector2.h"
#include "Collider.h"
#include "SphereCollider.h"
#include "BoxCollider.h"
#include "BinarySpacePartitioning.h";

class PhysicsEngine 
{
public:

	/// <summary>
	/// Updates the physical position of all rigidbodies
	/// </summary>
	/// <param name="deltaTime">The elapsed time between two frames</param>
	void PhysicsUpdate(float deltaTime);
	/// <summary>
	/// Checks the collision between two colliders
	/// </summary>
	/// <param name="me">The collider to check</param>
	/// <param name="other">The other collider with which the first one is checked</param>
	void CheckCollisions(Rigidbody* myRigidbody);
	/// <summary>
	/// Solves the collisions between two rigidbodies
	/// </summary>
	/// <param name="myBody">The first rigidbody</param>
	/// <param name="otherBody">The second rigidbody</param>
	void SolveCollision(Rigidbody* myBody, Rigidbody* otherBody);
	/// <summary>
	/// Solves the minimal translation vector (mtv) to place correctly two objects that are overlapping too much
	/// </summary>
	/// <param name="myBody">The first rigidbody</param>
	/// <param name="otherBody">The second rigidbody</param>
	/// <param name="mtv">The minimal translation vector (Vector2)</param>
	void SolveMTV(Rigidbody* myBody, Rigidbody* otherBody, Vector2& mtv);

	/// <summary>
	/// Register the Rigidbody in the PhysicsEngine
	/// </summary>
	/// <param name="rigidbody">The Rigidbody to register</param>
	void RegisterRigidbody(Rigidbody* rigidbody);
	/// <summary>
	/// Removes the Rigidbody from the PhysicsEngine
	/// </summary>
	/// <param name="rigidbody">The Rigidbody to remove</param>
	void RemoveRigidbody(Rigidbody* rigidbody);

	/// <summary>
	/// Adds a force the the physics engine
	/// </summary>
	/// <param name="force">The force to add (Vector2)</param>
	void AddForce(Vector2 force);
	/// <summary>
	/// Sets the gravity of the PhysicsEngine
	/// </summary>
	/// <param name="gravity">The gravity (Vector2)</param>
	void SetGravity(Vector2 gravity);
	/// <summary>
	/// Sets the gravity of the PhysicsEngine
	/// </summary>
	/// <param name="gravity">The Y value of gravity (float)(Vector2)</param>
	void SetGravity(float);
	
	/// <summary>
	/// Sets the Binary Space Partitioning member of the physics engine
	/// </summary>
	/// <param name="bsp">BSP</param>
	void SetBSP(BinarySpacePartitioning bsp);


private:

	std::vector<Rigidbody*> _rigidbodies;
	std::vector<Vector2> _forces;

	Vector2 _gravity = Vector2(0.0f, -9.81f);

	std::vector<std::pair<Rigidbody*, Rigidbody*>> _collisions;

	BinarySpacePartitioning _bsp;

	/// <summary>
	/// Adds a collision to the collision vector
	/// </summary>
	/// <param name="myBody">The first rigidbody</param>
	/// <param name="otherBody">The second rigidbody</param>
	void AddCollision(Rigidbody* myBody, Rigidbody* otherBody);
	/// <summary>
	/// Checks if the collision is already done
	/// </summary>
	/// <param name="myBody">The first rigidbody</param>
	/// <param name="otherBody">The second rigidbody</param>
	/// <returns>True if already done</returns>
	bool CheckCollisionDone(Rigidbody* myBody, Rigidbody* otherBody);
	/// <summary>
	/// Clears all the collisions from the collision vector
	/// </summary>
	void ClearCollisions();

};