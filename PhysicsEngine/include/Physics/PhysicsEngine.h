#pragma once
#include <vector>
#include "Maths/Vector2.h"
#include "Rigidbody.h"
#include "SphereCollider.h"

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
	void CheckCollisions(Rigidbody* myRigidbody);
	/// <summary>
	/// Solves the collisions between two rigidbodies
	/// </summary>
	/// <param name="myBody">The first rigidbody</param>
	/// <param name="otherBody">The second rigidbody</param>
	static void SolveCollision(Rigidbody* myBody, Rigidbody* otherBody);
	/// <summary>
	/// Solves the minimal translation vector (mtv) to place correctly two objects that are overlapping too much
	/// </summary>
	/// <param name="myBody">The first rigidbody</param>
	/// <param name="otherBody">The second rigidbody</param>
	/// <param name="mtv">The minimal translation vector (Vector2)</param>
	static void SolveMTV(Rigidbody* myBody, Rigidbody* otherBody, Vector2& mtv);

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
	void SetGravity(float gravity);

	/// <summary>
	/// Removes all rigidbodies
	/// </summary>
	void Clear();

	/// <summary>
	/// Gets the Gravity
	/// </summary>
	/// <returns>The gravity (Vector2)</returns>
	[[nodiscard]] Vector2 GetGravity() const;

private:

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
	bool CheckCollisionDone(Rigidbody* myBody, Rigidbody* otherBody) const;
	/// <summary>
	/// Clears all the collisions from the collision vector
	/// </summary>
	void ClearCollisions();

	std::vector<Rigidbody*> rigidbodies_{};
	std::vector<Vector2> forces_{};

	Vector2 gravity_ = Vector2{ 0.0f, 0.0f };

	std::vector<std::pair<Rigidbody*, Rigidbody*>> collisions_{};

};