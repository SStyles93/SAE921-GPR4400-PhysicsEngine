#pragma once
#include "Maths/Vector2.h"

class Collider
{
public:
	Collider();
	~Collider();

	virtual void SetCenter(const Vector2&) = 0;

	/// <summary>
	/// Gets the state of collision
	/// </summary>
	/// <returns>The state of collision (bool)</returns>
	bool IsColliding();
	/// <summary>
	/// Sets the state of collision
	/// </summary>
	/// <param name="value">The state to set (bool)</param>
	void IsColliding(const bool value);
	/// <summary>
	/// Base method for the Overlap with other objects
	/// </summary>
	/// <param name="myCollider">The collider to check</param>
	/// <returns>True if there is an overlap</returns>
	bool IsOverlapping(Collider* myCollider);

private:

	bool _isColliding = false;
};
