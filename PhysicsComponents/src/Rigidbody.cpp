#include "Rigidbody.h"

Rigidbody::Rigidbody(){}

Rigidbody::~Rigidbody(){}

/// <summary>
/// Gets the position of the Rigidbody
/// </summary>
/// <returns></returns>
Vector2& Rigidbody::GetPosition() 
{
	return _position;
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
/// Update the physics position of the Rigidbody
/// </summary>
void Rigidbody::UpdatePosition() 
{
	_position += Vector2(0.0f, (_gravity * _gravityScale) * _mass);
	_position += _velocity; /** _deltaTime;*/
}