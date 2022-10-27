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
	const float min2X = otherBox->GetCenter()._x - otherBox->GetHalfExtent()._x;
	const float max2X = otherBox->GetCenter()._x + otherBox->GetHalfExtent()._x;
	const float min2Y = otherBox->GetCenter()._y - otherBox->GetHalfExtent()._y;
	const float max2Y = otherBox->GetCenter()._y + otherBox->GetHalfExtent()._y;

	const float min1X = mySphere->GetCenter()._x - mySphere->GetRadius();
	const float max1X = mySphere->GetCenter()._x + mySphere->GetRadius();
	const float min1Y = mySphere->GetCenter()._y - mySphere->GetRadius();
	const float max1Y = mySphere->GetCenter()._y + mySphere->GetRadius();

	if ((max1X < min2X) ||
		(min1X > max2X))
	{
		return false;
	}
	if ((max1Y < min2Y) ||
		(min1Y > max2Y))
	{
		return false;
	}
	Vector2 distance = Vector2(otherBox->GetCenter() - mySphere->GetCenter());
	float distanceMagnitude = distance.Magnitude();
	float lenghtSum = otherBox->GetHalfExtent().Magnitude() + mySphere->GetRadius();

	float mtvDifference = lenghtSum - distanceMagnitude;
	mtv = distance.Normalized() * mtvDifference;

	return distanceMagnitude <= lenghtSum;
}