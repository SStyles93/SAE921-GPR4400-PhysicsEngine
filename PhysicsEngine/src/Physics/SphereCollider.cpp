#include "Physics/SphereCollider.h"

SphereCollider::SphereCollider(Vector2 center, float radius) : center_(center), radius_(radius) {}

Vector2& SphereCollider::GetCenter()
{
	return center_;
}
float& SphereCollider::GetRadius() 
{
	return radius_;
}

void SphereCollider::SetCenter(const Vector2& vector) 
{
	center_ = vector;
}
bool SphereCollider::IsOverlappingSphere(const SphereCollider* mySphere, const SphereCollider* otherSphere, Vector2& mtv) 
{
	const Vector2 distance = otherSphere->center_ - mySphere->center_;

	const float distanceMagnitude = distance.Magnitude();
	const float radiusSum = mySphere->radius_ + otherSphere->radius_;

	const float mtvDifference = radiusSum - distanceMagnitude;
	mtv = distance.Normalized() * mtvDifference;

	return (distanceMagnitude <= radiusSum);
}
