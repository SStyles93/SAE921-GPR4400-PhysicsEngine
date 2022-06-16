#pragma once
#include <cstdlib>
#include "Vector2.h"

class Rigidbody
{
public:

	Rigidbody();
	~Rigidbody();

	Vector2& GetPosition();

	void SetAcceleration(const Vector2&);
	void SetGravityScale(const float&);
	void SetMass(const float&);
	void SetPosition(const Vector2&);
	void SetRotation(const Vector2&);
	void SetVelocity(const Vector2&);

	void UpdatePosition();

private:

	float _gravity = -9.81f;
	float _gravityScale = 1.0f;
	float _mass = 0.0f;
	Vector2 _acceleration = Vector2(0.0f, 0.0f);
	Vector2 _position = Vector2(0.0f, 0.0f);
	Vector2 _rotation = Vector2(0.0f, 0.0f);
	Vector2 _velocity = Vector2(0.0f, 0.0f);
	
};