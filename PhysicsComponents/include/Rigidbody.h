#pragma once
#include <cstdlib>
#include "Vector2.h"
#include "Collider.h"
#include "SphereCollider.h"

class Rigidbody
{
public:

	Rigidbody();
	~Rigidbody();

	Vector2 GetAcceleration();
	Vector2 GetForce();
	Vector2 GetPosition();
	Vector2 GetRotation();
	Vector2 GetVelocity();
	float GetMass();
	float GetGravityScale();
	SphereCollider* GetSphereCollider();

	void AddForce(const Vector2&);
	void SetAcceleration(const Vector2&);
	void SetForce(const Vector2&);
	void SetPosition(const Vector2&);
	void SetRotation(const Vector2&);
	void SetVelocity(const Vector2&);
	void SetGravityScale(const float&);
	void SetMass(const float&);
	void SetSphereCollider(std::unique_ptr<SphereCollider>);

private:

	std::unique_ptr<SphereCollider> _sphereCollider;

	Vector2 _acceleration = Vector2(0.0f, 0.0f);
	Vector2 _force = Vector2(0.0f, 0.0f);
	Vector2 _position = Vector2(0.0f, 0.0f);
	Vector2 _rotation = Vector2(0.0f, 0.0f);
	Vector2 _velocity = Vector2(0.0f, 0.0f);
	
	float _gravityScale = 1.0f;
	float _mass = 0.0f;

};