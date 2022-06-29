#pragma once
#include "Collider.h"

class BoxCollider : public Collider
{
public:
	BoxCollider(Vector2, float);
	~BoxCollider();

	Vector2& GetCenter();

	void SetCenter(const Vector2&);

	static bool IsOverlappingBox(BoxCollider*, BoxCollider*, Vector2&);

private:

	Vector2 _plane;
	Vector2 _center;
	float distance;

};