#include "Rigidbody.h"

Rigidbody::Rigidbody(){}

Rigidbody::~Rigidbody(){}


/// <summary>
/// Get the acceleration of the rigidbody
/// </summary>
/// <returns>The acceleration (Vector2)</returns>
Vector2 Rigidbody::GetAcceleration() 
{
	return _acceleration;
}
/// <summary>
/// Get the force of the rigidbody
/// </summary>
/// <returns>Returns the force (Vector2)</returns>
Vector2 Rigidbody::GetForce() 
{
	return _force;
}
/// <summary>
/// Gets the position of the Rigidbody
/// </summary>
/// <returns>the acceleration (Vector2)</returns>
Vector2 Rigidbody::GetPosition() 
{
	return _position;
}
/// <summary>
/// Gets the rotation of the rigidbody
/// </summary>
/// <returns>Returns the rotation of the rigidbody (Vector2)</returns>
Vector2 Rigidbody::GetRotation()
{
	return _rotation;
}
/// <summary>
/// Gets the velocity of the rigidbody
/// </summary>
/// <returns>Returns the velocity (Vector2)</returns>
Vector2 Rigidbody::GetVelocity() 
{
	return _velocity;
}
/// <summary>
/// Gets the mass of the rigidbody
/// </summary>
/// <returns>Returns the mass (float)</returns>
float Rigidbody::GetMass() 
{
	return _mass;
}
/// <summary>
/// Gets the gravity scale of the rigidbody
/// </summary>
/// <returns>The gravity scale (float)</returns>
float Rigidbody::GetGravityScale() 
{
	return _gravityScale;
}
/// <summary>
/// Gets the collider of the reigidbody
/// </summary>
/// <returns>Collider</returns>
Collider* Rigidbody::GetCollider()
{
	return _collider.get();
}
bool Rigidbody::IsStatic() 
{
	return _isStatic;
}

/// <summary>
/// Adds a given force to Rigidbody
/// </summary>
/// <param name="force">The given force (Vector2)</param>
void Rigidbody::AddForce(const Vector2& force) 
{
	_force += force;
}
/// <summary>
/// Sets the acceleration of the Rigidbody
/// </summary>
/// <param name="acceleration">The acceleration</param>
void Rigidbody::SetAcceleration(const Vector2& acceleration) 
{
	_acceleration = acceleration;
}
/// <summary>
/// Sets the force of the rigidbody to the given force
/// </summary>
/// <param name="force">The given force (Vector2)</param>
void Rigidbody::SetForce(const Vector2& force) 
{
	_force = force;
}
/// <summary>
/// Sets the gravity scale of the rigidbody
/// </summary>
/// <param name="gravtityScale">The gravity scale of the rigidbody</param>
void Rigidbody::SetGravityScale(const float& gravtityScale) 
{
	_gravityScale = gravtityScale;
}
/// <summary>
/// Sets the mass of the object
/// </summary>
/// <param name="mass">The mass of the object</param>
void Rigidbody::SetMass(const float& mass) 
{
	_mass = mass;
}
/// <summary>
/// Sets the position of the object
/// </summary>
/// <param name="position"></param>
void Rigidbody::SetPosition(const Vector2& position) 
{
	_position = position;
}
/// <summary>
/// Sets the position of the object
/// </summary>
/// <param name="position"></param>
void Rigidbody::SetRotation(const Vector2& rotation)
{
	_rotation = rotation;
}
/// <summary>
/// Sets the position of the object
/// </summary>
/// <param name="position"></param>
void Rigidbody::SetVelocity(const Vector2& velocity)
{
	_velocity = velocity;
}
/// <summary>
/// Sets the collider to the given one
/// </summary>
/// <param name="collider">the collider to give (unique_ptr)</param>
void Rigidbody::SetCollider(std::unique_ptr<Collider> collider)
{
	_collider = std::move(collider);
}
/// <summary>
/// Defines is the body is Kinematic or not
/// </summary>
/// <param name="value">Set to false the body will be static</param>
void Rigidbody::IsKinematic(bool value) 
{
	_isStatic = !value;
}
/// <summary>
/// Sets the BoxCollider of the Rigidbody
/// </summary>
/// <param name="boxBollider">The box collider</param>
//void Rigidbody::SetBoxCollider(std::unique_ptr<BoxCollider> boxBollider) 
//{
//	_boxCollider = std::move(boxBollider);
//}


///// <summary>
///// Update the physics position of the Rigidbody
///// </summary>
//void Rigidbody::UpdatePosition() 
//{
//	//_position += Vector2(0.0f, (_gravity * _gravityScale) * _mass);
//	//_position += _velocity; /** _deltaTime;*/
//}