#pragma once
#include "Vector2.h"

class Collider
{
public:
	Collider();
	~Collider();

	virtual void SetCenter(const Vector2&) = 0;

	bool IsColliding();
	void IsColliding(const bool);
	bool IsOverlapping(Collider*);

private:

	bool _isColliding = false;
};
