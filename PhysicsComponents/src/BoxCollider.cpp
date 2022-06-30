#include "BoxCollider.h"

BoxCollider::BoxCollider(Vector2 center, float distance) : _center(center) 
{
	_halfExtent._x = (distance * 0.5f);
	_halfExtent._y = (distance * 0.5f);
}

BoxCollider::~BoxCollider(){}

/// <summary>
/// Gets the center of the BoxCollider
/// </summary>
/// <returns>The center (Vector2)</returns>
Vector2& BoxCollider::GetCenter() 
{
	return _center;
}

/// <summary>
/// Sets the center of the BoxCollider
/// </summary>
/// <param name="center">The center (Vector2)</param>
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
	return true;
}