#pragma once
#include "Collider.h"

class SphereCollider : public Collider
{
public:

	SphereCollider(Vector2, float);
	~SphereCollider();

	Vector2& GetCenter();
	void SetCenter(const Vector2&) override;
	
	static bool IsOverlappingSphere(SphereCollider*, SphereCollider*, Vector2&);

private:

	Vector2 _center;
	float _radius;

};