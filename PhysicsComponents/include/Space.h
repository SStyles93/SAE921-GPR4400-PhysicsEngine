#pragma once
#include "Vector2.h"
#include "Rigidbody.h"

class Space
{
public:

	/// <summary>
	/// Constructor for the Space
	/// </summary>
	/// <param name="minPoint">The minial position of the space (lower-left corner)</param>
	/// <param name="maxPoint">The maximal position of the space (upper-right corner)</param>
	Space(Vector2 minPoint, Vector2 maxPoint);
	Space();
	~Space();

	/// <summary>
	/// Gets the minimal point of the space
	/// </summary>
	/// <returns>The minimal point (Vector2)</returns>
	Vector2 GetMin();
	/// <summary>
	/// Gets the maximal point of the space
	/// </summary>
	/// <returns>The maximal point (Vector2)</returns>
	Vector2 GetMax();
	/// <summary>
	/// Gets the Surface of the Space
	/// </summary>
	/// <returns>The surface of the space (float)</returns>
	float GetSurface();
	/// <summary>
	/// Gets the Size of the X side
	/// </summary>
	/// <returns>Size of the X side (float)</returns>
	float GetSizeX();
	/// <summary>
	/// Gets the Size of the Y side
	/// </summary>
	/// <returns>Size of the Y side (float)</returns>
	float GetSizeY();
	/// <summary>
	/// Gets the Square Magnitude of the Space
	/// </summary>
	/// <returns>The SquareMagnitude of the Space (float)</returns>
	float GetSrqMagnitude();

	/// <summary>
	/// Checks if the space contains the rigidbody
	/// </summary>
	/// <param name="rigidbody">The given rigidbody</param>
	/// <returns>True if space contains the rigidbody</returns>
	bool Contains(Rigidbody*);

private:

	Vector2 _minPoint;
	Vector2 _maxPoint;
};
