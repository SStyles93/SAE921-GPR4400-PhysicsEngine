#pragma once
#include "Collider.h"

class SphereCollider : public Collider
{
public:

	/// <summary>
	/// SphereConstructor
	/// </summary>
	/// <param name="center">The center of the sphere (Vector2)</param>
	/// <param name="radius">The radius of the sphere (float)</param>
	SphereCollider(Vector2 center, float radius);

	/// <summary>
	/// Gets the center of the SphereCollider
	/// </summary>
	/// <returns>The center (Vector2)</returns>
	Vector2& GetCenter();
	/// <summary>
	/// Gets the radius of the SphereCollider
	/// </summary>
	/// <returns>The radius (float)</returns>
	float& GetRadius();

	/// <summary>
	/// Sets the center of the SphereCollider
	/// </summary>
	/// <param name="vector">The center (Vector2)</param>
	void SetCenter(const Vector2& vector) override;
	/// <summary>
	/// Checks if the SphereCollider is overlapping with an other SphereCollider
	/// </summary>
	/// <param name="mySphere">The first SphereCollider</param>
	/// <param name="otherSphere">The second SphereCollider</param>
	/// <param name="mtv">The minimum translation vector from the overlapping (Vector2)</param>
	/// <returns>True if SphereColliders are overlapping</returns>
	static bool IsOverlappingSphere(const SphereCollider* mySphere, const SphereCollider* otherSphere, Vector2& mtv);

private:

	Vector2 center_;
	float radius_;

};