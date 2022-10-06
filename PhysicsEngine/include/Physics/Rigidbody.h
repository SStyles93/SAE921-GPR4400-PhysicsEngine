#pragma once
#include "Maths/Vector2.h"
#include "Collider.h"

class Rigidbody
{
public:
#pragma region Getters

	/// <summary>
	/// Get the acceleration of the rigidbody
	/// </summary>
	/// <returns>The acceleration (Vector2)</returns>
	[[nodiscard]] Vector2 GetAcceleration() const;
	/// <summary>
	/// Get the force of the rigidbody
	/// </summary>
	/// <returns>Returns the force (Vector2)</returns>
	[[nodiscard]] auto GetForce() const -> Vector2;
	/// <summary>
	/// Gets the position of the Rigidbody
	/// </summary>
	/// <returns>the acceleration (Vector2)</returns>
	[[nodiscard]] Vector2 GetPosition() const;
	/// <summary>
	/// Gets the rotation of the rigidbody
	/// </summary>
	/// <returns>Returns the rotation of the rigidbody (Vector2)</returns>
	[[nodiscard]] Vector2 GetRotation() const;
	/// <summary>
	/// Gets the velocity of the rigidbody
	/// </summary>
	/// <returns>Returns the velocity (Vector2)</returns>
	[[nodiscard]] Vector2 GetVelocity() const;
	/// <summary>
	/// Gets the collider of the reigidbody
	/// </summary>
	/// <returns>Collider</returns>
	[[nodiscard]] Collider* GetCollider() const;
	/// <summary>
	/// Gets the bounciness of the rigidbody
	/// </summary>
	/// <returns>Returns the bounciness (float)</returns>
	[[nodiscard]] float GetBounciness() const;
	/// <summary>
	/// Gets the mass of the rigidbody
	/// </summary>
	/// <returns>Returns the mass (float)</returns>
	[[nodiscard]] float GetMass() const;
	/// <summary>
	/// Gets the gravity scale of the rigidbody
	/// </summary>
	/// <returns>The gravity scale (float)</returns>
	[[nodiscard]] float GetGravityScale() const;
	/// <summary>
	/// Gets the BSP ID
	/// </summary>
	/// <returns>The ID of the rigidbody (int, for BSP)</returns>
	[[nodiscard]] int GetId() const;
	/// <summary>
	/// Retruns the Kinematic state of the rigidbody
	/// </summary>
	/// <returns>True if the rigidbody is static</returns>
	[[nodiscard]] bool IsStatic() const;

#pragma endregion
#pragma region Setters

	/// <summary>
	/// Adds a given force to Rigidbody
	/// </summary>
	/// <param name="force">The given force (Vector2)</param>
	void AddForce(Vector2 const & force);
	/// <summary>
	/// Defines is the body is Kinematic or not
	/// </summary>
	/// <param name="value">Set to false the body will be static</param>
	void IsKinematic(bool value);
	/// <summary>
	/// Sets the acceleration of the Rigidbody
	/// </summary>
	/// <param name="acceleration">The acceleration</param>
	void SetAcceleration(Vector2 const & acceleration);
	/// <summary>
	/// Sets the bounciness of the rigidbody
	/// </summary>
	/// <param name="bounciness">The bounciness value (float)</param>
	void SetBounciness(float const & bounciness);
	/// <summary>
	/// Sets the collider to the given one
	/// </summary>
	/// <param name="collider">the collider to give (unique_ptr)</param>
	void SetCollider(std::unique_ptr<Collider> collider);
	/// <summary>
	/// Sets the force of the rigidbody to the given force
	/// </summary>
	/// <param name="force">The given force (Vector2)</param>
	void SetForce(Vector2 const & force);
	/// <summary>
	/// Sets the gravity scale of the rigidbody
	/// </summary>
	/// <param name="gravtityScale">The gravity scale of the rigidbody</param>
	void SetGravityScale(float const & gravtityScale);
	/// <summary>
	/// Sets the collision ID for the BSP
	/// </summary>
	/// <param name="id">The collision ID</param>
	void SetId(int id);
	/// <summary>
	/// Sets the mass of the object
	/// </summary>
	/// <param name="mass">The mass of the object</param>
	void SetMass(float const & mass);
	/// <summary>
	/// Sets the position of the object
	/// </summary>
	/// <param name="position">The position (Vector2)</param>
	void SetPosition(Vector2 const & position);
	/// <summary>
	/// Sets the position of the object
	/// </summary>
	/// <param name="position"></param>
	void SetRotation(Vector2 const & rotation);
	/// <summary>
	/// Sets the velocity of the object
	/// </summary>
	/// <param name="velocity">The velocity (Vector2)</param>
	void SetVelocity(Vector2 const & velocity);

#pragma endregion

private:

	std::unique_ptr<Collider> collider_;

	Vector2 acceleration_ = Vector2{ 0.0f, 0.0f };
	Vector2 force_ = Vector2{ 0.0f, 0.0f };
	Vector2 position_ = Vector2{0.0f, 0.0f};
	Vector2 rotation_ = Vector2{0.0f, 0.0f};
	Vector2 velocity_ = Vector2{0.0f, 0.0f};
	
	float bounciness_ = 1.0f;
	float gravityScale_ = 1.0f;
	float mass_ = 0.0f;

	bool isStatic_ = false;

	int id_ = -2;

};