#include "Rigidbody.h"

Rigidbody::Rigidbody(){}
Rigidbody::~Rigidbody(){}

#pragma region Getters

Vector2 Rigidbody::GetAcceleration() 
{
	return _acceleration;
}
Vector2 Rigidbody::GetForce() 
{
	return _force;
}
Vector2 Rigidbody::GetPosition() 
{
	return _position;
}
Vector2 Rigidbody::GetRotation()
{
	return _rotation;
}
Vector2 Rigidbody::GetVelocity() 
{
	return _velocity;
}
Collider* Rigidbody::GetCollider()
{
	return _collider.get();
}
float Rigidbody::GetBounciness() 
{
	return _bounciness;
}
float Rigidbody::GetMass() 
{
	return _mass;
}
float Rigidbody::GetGravityScale() 
{
	return _gravityScale;
}
bool Rigidbody::IsStatic() 
{
	return _isStatic;
}
int Rigidbody::GetId()
{
	return _id;
}

#pragma endregion
#pragma region Setters

void Rigidbody::AddForce(const Vector2& force) 
{
	_force += force;
}
void Rigidbody::IsKinematic(bool value)
{
	_isStatic = !value;
}
void Rigidbody::SetAcceleration(const Vector2& acceleration) 
{
	_acceleration = acceleration;
}
void Rigidbody::SetBounciness(const float& bounciness)
{
	_bounciness = bounciness;
}
void Rigidbody::SetCollider(std::unique_ptr<Collider> collider)
{
	_collider = std::move(collider);
}
void Rigidbody::SetForce(const Vector2& force) 
{
	_force = force;
}
void Rigidbody::SetGravityScale(const float& gravtityScale) 
{
	_gravityScale = gravtityScale;
}
void Rigidbody::SetId(int id)
{
	_id = id;
}
void Rigidbody::SetMass(const float& mass) 
{
	_mass = mass;
}
void Rigidbody::SetPosition(const Vector2& position) 
{
	_position = position;
}
void Rigidbody::SetRotation(const Vector2& rotation)
{
	_rotation = rotation;
}
void Rigidbody::SetVelocity(const Vector2& velocity)
{
	_velocity = velocity;
}

#pragma endregion