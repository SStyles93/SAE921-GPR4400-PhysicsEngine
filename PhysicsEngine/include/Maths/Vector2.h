#pragma once
#include <SFML/Graphics.hpp>
#include <string>

struct Vector2
{
public:

	Vector2();

	/// <summary>
	/// Vector2 constructor
	/// </summary>
	/// <param name="x">The X value of the Vector (float)</param>
	/// <param name="y">The Y value of the Vector (float)</param>
	Vector2(float x, float y);
	
	/// <summary>
	/// Magnitude of this Vector
	/// </summary>
	/// <returns>The Magnitude</returns>
	[[nodiscard]] float Magnitude() const;
	/// <summary>
	/// SquaredMagnitude of this Vector
	/// </summary>
	/// <returns>The Squared Magnitude</returns>
	[[nodiscard]] float SqrMagnitude() const;
	/// <summary>
	/// Gives the Dot product of this vector and the given one in parameter
	/// </summary>
	/// <param name="v1">Vector used for the dot product</param>
	/// <returns>The Dot Product of the two given Vectors</returns>
	[[nodiscard]] float Dot(const Vector2& v1) const;
	/// <summary>
	/// Normalizes this Vector
	/// </summary>
	/// <returns>The Normalized Vector</returns>
	[[nodiscard]] Vector2 Normalized() const;
	/// <summary>
	/// Returns the right tengent of a vector
	/// </summary>
	/// <returns>The right tengent (Vector2)</returns>
	auto RightOrtho() -> Vector2;
	/// <summary>
	/// Returns the left tengent of a vector
	/// </summary>
	/// <returns>The left tengent (Vector2)</returns>
	auto LeftOrtho() -> Vector2;
	/// <summary>
	/// Outputs the X and Y values
	/// </summary>
	/// <returns>The X and Y in an std::string</returns>
	[[nodiscard]] std::string ToString() const;
	
	/// <summary>
	/// Sets the origin of the Vector2
	/// </summary>
	/// <param name="origin">Vector2 origin of the vector</param>
	static void SetOrigin(const Vector2& origin);

	//Operator overloading
	Vector2 operator+(const Vector2&) const;
	Vector2 operator-(const Vector2&) const;
	Vector2 operator+=(const Vector2&);
	Vector2 operator-=(const Vector2&);
	Vector2 operator/(const float&) const;
	Vector2 operator*(const float&) const;
	friend std::ostream& operator<<(std::ostream&,const Vector2&);

	float x{};
	float y{};
};