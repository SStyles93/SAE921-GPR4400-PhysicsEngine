#include "Physics/Space.h"

Space::Space(Vector2 minPoint, Vector2 maxPoint) : _minPoint(minPoint), _maxPoint(maxPoint) {}
Space::Space() {}
Space::~Space() {}

Vector2 Space::GetMin()
{
	return _minPoint;
}
Vector2 Space::GetMax()
{
	return _maxPoint;
}
float Space::GetSurface() 
{
	return (_maxPoint._x - _minPoint._x) * (_maxPoint._y - _minPoint._y);
}
float Space::GetSizeX() 
{
	return _maxPoint._x - _minPoint._x;
}
float Space::GetSizeY()
{
	return _maxPoint._y - _minPoint._y;
}
float Space::GetSrqMagnitude() 
{
	return (this->GetMax() - this->GetMin()).SqrMagnitude();
}

bool Space::Contains(Rigidbody* rigidbody) 
{
	if (rigidbody->GetPosition()._x < _minPoint._x || rigidbody->GetPosition()._x > _maxPoint._x) return false;
	if (rigidbody->GetPosition()._y < _minPoint._y || rigidbody->GetPosition()._y > _maxPoint._y) return false;

	return true;

}