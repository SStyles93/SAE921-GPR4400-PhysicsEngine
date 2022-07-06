#include "Space.h"

/// <summary>
/// Constructor for the Space
/// </summary>
/// <param name="minPoint">The minial position of the space (lower-left corner)</param>
/// <param name="maxPoint">The maximal position of the space (upper-right corner)</param>
Space::Space(Vector2 minPoint, Vector2 maxPoint) : _minPoint(minPoint), _maxPoint(maxPoint) {}

Space::Space() {}

Space::~Space() {}

/// <summary>
/// Gets the minimal point of the space
/// </summary>
/// <returns>The minimal point (Vector2)</returns>
Vector2 Space::GetMin()
{
	return _minPoint;
}

/// <summary>
/// Gets the maximal point of the space
/// </summary>
/// <returns>The maximal point (Vector2)</returns>
Vector2 Space::GetMax()
{
	return _maxPoint;
}

/// <summary>
/// Gets the Surface of the Space
/// </summary>
/// <returns>The surface of the space (float)</returns>
float Space::GetSurface() 
{
	return (_maxPoint._x - _minPoint._x) * (_maxPoint._y - _minPoint._y);
}

/// <summary>
/// Gets the Size of the X side
/// </summary>
/// <returns>Size of the X side (float)</returns>
float Space::GetSizeX() 
{
	return _maxPoint._x - _minPoint._x;
}

/// <summary>
/// Gets the Size of the Y side
/// </summary>
/// <returns>Size of the Y side (float)</returns>
float Space::GetSizeY()
{
	return _maxPoint._y - _minPoint._y;
}

/// <summary>
/// Gets the Square Magnitude of the Space
/// </summary>
/// <returns>The SquareMagnitude of the Space (float)</returns>
float Space::GetSrqMagnitude() 
{
	return (this->GetMax() - this->GetMin()).SqrMagnitude();
}

/// <summary>
/// Checks if the space contains the rigidbody
/// </summary>
/// <param name="rigidbody">The given rigidbody</param>
/// <returns>True if space contains the rigidbody</returns>
bool Space::Contains(Rigidbody* rigidbody) 
{
	if (rigidbody->GetPosition()._x < _minPoint._x || rigidbody->GetPosition()._x > _maxPoint._x) return false;
	if (rigidbody->GetPosition()._y < _minPoint._y || rigidbody->GetPosition()._y > _maxPoint._y) return false;

	return true;

}