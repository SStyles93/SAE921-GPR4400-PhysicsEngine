#pragma once
#include "Vector2.h"
#include "Rigidbody.h"

class Space
{
public:
	Space();
	Space(const Vector2, const Vector2);
	~Space();

	Vector2 GetMin();
	Vector2 GetMax();
	float GetSurface();
	float GetSizeX();
	float GetSizeY();
	float GetSrqMagnitude();

	bool Contains(Rigidbody*);

private:

	Vector2 _minPoint;
	Vector2 _maxPoint;
};
