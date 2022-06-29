#include "Collider.h"

Collider::Collider(){}

Collider::~Collider(){}

bool Collider::IsColliding() 
{
	return _isColliding;
}

void Collider::IsColliding(const bool value) 
{
	_isColliding = value;
}

bool Collider::IsOverlapping(Collider* myCollider) 
{
	return true;
}