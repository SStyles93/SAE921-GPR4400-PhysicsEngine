#include "Physics/BoxCollider.h"

BoxCollider::BoxCollider(Vector2 center, float size) : _center(center) 
{
	_halfExtent._x = (size * 0.5f);
	_halfExtent._y = (size * 0.5f);
}
BoxCollider::BoxCollider(Vector2 center, float sizeX, float sizeY) : _center(center)
{
	_halfExtent._x = (sizeX * 0.5f);
	_halfExtent._y = (sizeY * 0.5f);
}
BoxCollider::BoxCollider(Vector2 center, Vector2 size) : _center(center)
{
	_halfExtent._x = (size._x * 0.5f);
	_halfExtent._y = (size._y * 0.5f);
}
BoxCollider::~BoxCollider(){}

Vector2& BoxCollider::GetCenter() 
{
	return _center;
}
Vector2& BoxCollider::GetHalfExtent() 
{
	return _halfExtent;
}
void BoxCollider::SetCenter(const Vector2& center) 
{
	_center = center;
}

bool BoxCollider::IsOverlappingBox(BoxCollider* myBox, BoxCollider* otherBox, Vector2& mtv) 
{
	float min1X = myBox->_center._x - myBox->_halfExtent._x;
	float max1X = myBox->_center._x + myBox->_halfExtent._x;
	float min1Y = myBox->_center._y - myBox->_halfExtent._y;
	float max1Y = myBox->_center._y + myBox->_halfExtent._y;

	float min2X = otherBox->_center._x - otherBox->_halfExtent._x;
	float max2X = otherBox->_center._x + otherBox->_halfExtent._x;
	float min2Y = otherBox->_center._y - otherBox->_halfExtent._y;
	float max2Y = otherBox->_center._y + otherBox->_halfExtent._y;

	if (max1X < min2X || min1X > max2X) return false;
	if (max1Y < min2Y || min1Y > max2Y) return false;

	Vector2 distance = Vector2(otherBox->_center - myBox->_center);
	float distanceMagnitude = distance.Magnitude();
	float lenghtSum = myBox->_halfExtent.Magnitude() + otherBox->_halfExtent.Magnitude();

	float mtvDifference = lenghtSum - distanceMagnitude;
	mtv = distance.Normalized() * mtvDifference;

	return true;
}
bool BoxCollider::IsOverlappingSphere(BoxCollider* myBox, SphereCollider* otherSphere, Vector2& mtv) 
{
	Vector2 distance = otherSphere->GetCenter() - myBox->_center;

	float distanceMagnitude = distance.Magnitude();
	float radiusSum = myBox->_halfExtent.Magnitude() + otherSphere->GetRadius();

	float mtvDifference = radiusSum - distanceMagnitude;
	mtv = distance.Normalized() * -mtvDifference;

	return (distanceMagnitude <= radiusSum);
}