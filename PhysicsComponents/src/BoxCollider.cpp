#include "BoxCollider.h"

BoxCollider::BoxCollider(Vector2 plane, float distance) : _plane(plane), _distance(distance)
{
	_center = Vector2(_plane._x * distance * 0.5f, _plane._y * distance * 0.5f);
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
	if (myBox->_plane._x + (myBox->_plane._x * _distance) < otherBox->_plane._x ||
		myBox->_plane._x > otherBox->_plane._x + (otherBox->_plane._x * _distance)) return false;

	if (myBox->_plane._y + (myBox->_plane._y * _distance) < otherBox->_plane._y ||
		myBox->_plane._y > otherBox->_plane._y + (otherBox->_plane._y * _distance)) return false;

	return true;
}