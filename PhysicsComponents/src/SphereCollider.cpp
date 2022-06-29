#include "SphereCollider.h"

/// <summary>
/// SphereConstructor
/// </summary>
/// <param name="center">The center of the sphere (Vector2)</param>
/// <param name="radius">The radius of the sphere (float)</param>
SphereCollider::SphereCollider(Vector2 center, float radius) : _center(center), _radius(radius) {}

SphereCollider::~SphereCollider(){}

Vector2& SphereCollider::GetCenter()
{
	return _center;
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