#pragma once
#include <cstdlib>
#include "Vector2.h"
#include "Collider.h"
#include "SphereCollider.h"
#include "BoxCollider.h"

class Rigidbody
{
public:

	Rigidbody();
	~Rigidbody();

#pragma region Getters

	/// <summary>
	/// Get the acceleration of the rigidbody
	/// </summary>
	/// <returns>The acceleration (Vector2)</returns>
	Vector2 GetAcceleration();
	/// <summary>
	/// Get the force of the rigidbody
	/// </summary>
	/// <returns>Returns the force (Vector2)</returns>
	Vector2 GetForce();
	/// <summary>
	/// Gets the position of the Rigidbody
	/// </summary>
	/// <returns>the acceleration (Vector2)</returns>
	Vector2 GetPosition();
	/// <summary>
	/// Gets the rotation of the rigidbody
	/// </summary>
	/// <returns>Returns the rotation of the rigidbody (Vector2)</returns>
	Vector2 GetRotation();
	/// <summary>
	/// Gets the velocity of the rigidbody
	/// </summary>
	/// <returns>Returns the velocity (Vector2)</returns>
	Vector2 GetVelocity();
	/// <summary>
	/// Gets the collider of the reigidbody
	/// </summary>
	/// <returns>Collider</returns>
	Collider* GetCollider();
	/// <summary>
	/// Gets the bounciness of the rigidbody
	/// </summary>
	/// <returns>Returns the bounciness (float)</returns>
	float GetBounciness();
	/// <summary>
	/// Gets the mass of the rigidbody
	/// </summary>
	/// <returns>Returns the mass (float)</returns>
	float GetMass();
	/// <summary>
	/// Gets the gravity scale of the rigidbody
	/// </summary>
	/// <returns>The gravity scale (float)</returns>
	float GetGravityScale();
	/// <summary>
	/// Gets the BSP ID
	/// </summary>
	/// <returns>The ID of the rigidbody (int, for BSP)</returns>
	int GetId();
	/// <summary>
	/// Retruns the Kinematic state of the rigidbody
	/// </summary>
	/// <returns>True if the rigidbody is static</returns>
	bool IsStatic();

#pragma endregion
#pragma region Setters

	/// <summary>
	/// Adds a given force to Rigidbody
	/// </summary>
	/// <param name="force">The given force (Vector2)</param>
	void AddForce(const Vector2& force);
	/// <summary>
	/// Defines is the body is Kinematic or not
	/// </summary>
	/// <param name="value">Set to false the body will be static</param>
	void IsKinematic(bool value);
	/// <summary>
	/// Sets the acceleration of the Rigidbody
	/// </summary>
	/// <param name="acceleration">The acceleration</param>
	void SetAcceleration(const Vector2& acceleration);
	/// <summary>
	/// Sets the bounciness of the rigidbody
	/// </summary>
	/// <param name="bounciness">The bounciness value (float)</param>
	void SetBounciness(const float& bounciness);
	/// <summary>
	/// Sets the collider to the given one
	/// </summary>
	/// <param name="collider">the collider to give (unique_ptr)</param>
	void SetCollider(std::unique_ptr<Collider> collider);
	/// <summary>
	/// Sets the force of the rigidbody to the given force
	/// </summary>
	/// <param name="force">The given force (Vector2)</param>
	void SetForce(const Vector2& force);
	/// <summary>
	/// Sets the gravity scale of the rigidbody
	/// </summary>
	/// <param name="gravtityScale">The gravity scale of the rigidbody</param>
	void SetGravityScale(const float& gravtityScale);
	/// <summary>
	/// Sets the collision ID for the BSP
	/// </summary>
	/// <param name="id">The collision ID</param>
	void SetId(int id);
	/// <summary>
	/// Sets the mass of the object
	/// </summary>
	/// <param name="mass">The mass of the object</param>
	void SetMass(const float& mass);
	/// <summary>
	/// Sets the position of the object
	/// </summary>
	/// <param name="position">The position (Vector2)</param>
	void SetPosition(const Vector2& position);
	/// <summary>
	/// Sets the position of the object
	/// </summary>
	/// <param name="position"></param>
	void SetRotation(const Vector2& rotation);
	/// <summary>
	/// Sets the velocity of the object
	/// </summary>
	/// <param name="velocity">The velocity (Vector2)</param>
	void SetVelocity(const Vector2& velocity);

#pragma endregion

private:

	std::unique_ptr<Collider> _collider;

	Vector2 _acceleration = Vector2(0.0f, 0.0f);
	Vector2 _force = Vector2(0.0f, 0.0f);
	Vector2 _position = Vector2(0.0f, 0.0f);
	Vector2 _rotation = Vector2(0.0f, 0.0f);
	Vector2 _velocity = Vector2(0.0f, 0.0f);
	
	float _bounciness = 1.0f;
	float _gravityScale = 1.0f;
	float _mass = 0.0f;

	bool _isStatic = false;

	int _id = -1;

};