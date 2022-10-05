#pragma once
#include "Maths/Vector2.h"

class Collider
{
public:
	virtual ~Collider() = default;
	virtual void SetCenter(const Vector2&) = 0;

	/// <summary>
	/// Gets the state of collision
	/// </summary>
	/// <returns>The state of collision (bool)</returns>
	[[nodiscard]] bool IsColliding() const;
	/// <summary>
	/// Sets the state of collision
	/// </summary>
	/// <param name="value">The state to set (bool)</param>
	void IsColliding(bool value);
	/// <summary>
	/// Base method for the Overlap with other objects
	/// </summary>
	/// <returns>True if there is an overlap</returns>
	[[nodiscard]] auto IsOverlapping() const -> bool;
	/// <summary>
	/// Sets the state of overlap.
	/// </summary>
	/// <param name="value">the overlap state (bool)</param>
	void IsOverlapping(bool value);

private:

	bool isColliding_ = false;
	bool isOverlapping_ = false;
};
