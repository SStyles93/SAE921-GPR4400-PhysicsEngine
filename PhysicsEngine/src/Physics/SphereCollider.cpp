#include "Physics/SphereCollider.h"

SphereCollider::SphereCollider(Vector2 center, float radius) : _center(center), _radius(radius) {}
SphereCollider::~SphereCollider(){}

Vector2& SphereCollider::GetCenter()
{
	return _center;
}
float& SphereCollider::GetRadius() 
{
	return _radius;
}

void SphereCollider::SetCenter(const Vector2& vector) 
{
	_center = vector;
}
bool SphereCollider::IsOverlappingSphere(SphereCollider* mySphere, SphereCollider* otherSphere, Vector2& mtv) 
{
	Vector2 distance = otherSphere->_center - mySphere->_center;

	float distanceMagnitude = distance.Magnitude();
	float radiusSum = mySphere->_radius + otherSphere->_radius;

	float mtvDifference = radiusSum - distanceMagnitude;
	mtv = distance.Normalized() * mtvDifference;

	return (distanceMagnitude <= radiusSum);
}
bool SphereCollider::IsOverlappingBox(SphereCollider* mySphere, BoxCollider* otherBox, Vector2& mtv)
{
	Vector2 distance = otherBox->GetCenter() - mySphere->GetCenter();

	float distanceMagnitude = distance.Magnitude();
	float radiusSum = mySphere->GetRadius() + otherBox->GetHalfExtent().Magnitude();

	float mtvDifference = radiusSum - distanceMagnitude;
	mtv = distance.Normalized() * -mtvDifference;

	return (distanceMagnitude <= radiusSum);
}