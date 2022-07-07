#pragma once
#include "Collider.h"
#include "SphereCollider.h"

class BoxCollider : public Collider
{
public:
	/// <summary>
	/// BoxCollider constructor
	/// </summary>
	/// <param name="center">The center of the box (Vector2)</param>
	/// <param name="size">The size in X and Y of the box</param>
	BoxCollider(Vector2 center, float size);
	/// <summary>
	/// BoxCollider constructor
	/// </summary>
	/// <param name="center">The center of the box (Vector2)</param>
	/// <param name="sizeX">The X size of the box</param>
	/// <param name="sizeY">The Y size of the box</param>
	BoxCollider(Vector2 center, float sizeX, float sizeY);
	/// <summary>
	/// BoxCollider constructor
	/// </summary>
	/// <param name="center">The center of the box (Vector2)</param>
	/// <param name="size">The size in X and Y of the box (Vector2)</param>
	BoxCollider(Vector2 center, Vector2 size);
	~BoxCollider();

	/// <summary>
	/// Gets the center of the BoxCollider
	/// </summary>
	/// <returns>The center (Vector2)</returns>
	Vector2& GetCenter();
	/// <summary>
	/// Sets the center of the BoxCollider
	/// </summary>
	/// <param name="center">The center (Vector2)</param>
	void SetCenter(const Vector2& center) override;

	/// <summary>
	/// Checks if this BoxCollider is overlapping with another BoxCollider
	/// </summary>
	/// <param name="myBox">This BoxCollider</param>
	/// <param name="otherBox">The other BoxCollider</param>
	/// <param name="mtv">The minimal translation vector</param>
	/// <returns>True is there is an overlap</returns>
	static bool IsOverlappingBox(BoxCollider* myBox, BoxCollider* otherBox, Vector2& mtv);
	/// <summary>
	/// Checks if this BoxCollider is overlapping with another BoxCollider
	/// </summary>
	/// <param name="myBox">This BoxCollider</param>
	/// <param name="sphereCollider">The other SphereCollider</param>
	/// <param name="mtv">The minimal translation vector</param>
	/// <returns>True is there is an overlap</returns>
	static bool IsOverlappingSphere(BoxCollider* myBox, SphereCollider* sphereCollider, Vector2& mtv);

private:

	Vector2 _center;
	Vector2 _halfExtent;

};