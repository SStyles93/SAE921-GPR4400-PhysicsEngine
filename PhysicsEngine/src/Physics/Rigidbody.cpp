#include "Physics/Rigidbody.h"

#pragma region Getters

Vector2 Rigidbody::GetAcceleration() const
{
	return acceleration_;
}
Vector2 Rigidbody::GetForce() const
{
	return force_;
}
Vector2 Rigidbody::GetPosition() const
{
	return position_;
}
Vector2 Rigidbody::GetRotation() const
{
	return rotation_;
}
Vector2 Rigidbody::GetVelocity() const
{
	return velocity_;
}
Collider* Rigidbody::GetCollider() const
{
	return collider_.get();
}
float Rigidbody::GetBounciness() const
{
	return bounciness_;
}
float Rigidbody::GetMass() const
{
	return mass_;
}
float Rigidbody::GetGravityScale() const
{
	return gravityScale_;
}
bool Rigidbody::IsStatic() const
{
	return isStatic_;
}
int Rigidbody::GetId() const
{
	return id_;
}

#pragma endregion
#pragma region Setters

void Rigidbody::AddForce(const Vector2& force) 
{
	force_ += force;
}
void Rigidbody::IsKinematic(bool value)
{
	isStatic_ = !value;
}
void Rigidbody::SetAcceleration(const Vector2& acceleration) 
{
	acceleration_ = acceleration;
}
void Rigidbody::SetBounciness(const float& bounciness)
{
	bounciness_ = bounciness;
}
void Rigidbody::SetCollider(std::unique_ptr<Collider> collider)
{
	collider_ = std::move(collider);
}
void Rigidbody::SetForce(const Vector2& force) 
{
	force_ = force;
}
void Rigidbody::SetGravityScale(const float& gravtityScale) 
{
	gravityScale_ = gravtityScale;
}
void Rigidbody::SetId(int id)
{
	id_ = id;
}
void Rigidbody::SetMass(const float& mass) 
{
	mass_ = mass;
}
void Rigidbody::SetPosition(const Vector2& position) 
{
	position_ = position;
}
void Rigidbody::SetRotation(const Vector2& rotation)
{
	rotation_ = rotation;
}
void Rigidbody::SetVelocity(const Vector2& velocity)
{
	velocity_ = velocity;
}

#pragma endregion