#include "Physics/Collider.h"

bool Collider::IsColliding() const
{
	return isColliding_;
}
void Collider::IsColliding(const bool value)
{
	isColliding_ = value;
}
bool Collider::IsOverlapping() const
{
	return isOverlapping_;
}
void Collider::IsOverlapping(bool value) 
{
	isOverlapping_ = value;
}