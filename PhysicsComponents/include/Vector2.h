#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

struct Vector2 /*: public sf::Drawable, public sf::Transformable*/
{
public:

	/// <summary>
	/// Vector2 constructor
	/// </summary>
	/// <param name="x">The X value of the Vector (float)</param>
	/// <param name="y">The Y value of the Vector (float)</param>
	Vector2(const float x, const float y);
	Vector2();
	~Vector2();
	
	/// <summary>
	/// Magnitude of this Vector
	/// </summary>
	/// <returns>The Magnitude</returns>
	float Magnitude();
	/// <summary>
	/// SquaredMagnitude of this Vector
	/// </summary>
	/// <returns>The Squared Magnitude</returns>
	float SqrMagnitude();
	/// <summary>
	/// Gives the Dot product of this vector and the given one in parameter
	/// </summary>
	/// <param name="v1">Vector used for the dot product</param>
	/// <returns>The Dot Product of the two given Vectors</returns>
	float Dot(const Vector2& v1);
	/// <summary>
	/// Normalizes this Vector
	/// </summary>
	/// <returns>The Normalized Vector</returns>
	Vector2 Normalized();
	/// <summary>
	/// Returns the right tengent of a vector
	/// </summary>
	/// <returns>The right tengent (Vector2)</returns>
	Vector2 RightOrtho();
	/// <summary>
	/// Returns the left tengent of a vector
	/// </summary>
	/// <returns>The left tengetn (Vector2)</returns>
	Vector2 LeftOrtho();

	/// <summary>
	/// Sets the origin of the Vector2
	/// </summary>
	/// <param name="origin">Vector2 origin of the vector</param>
	void SetOrigin(const Vector2& origin);
	/*void draw(sf::RenderTarget&, sf::RenderStates) const override;*/

	//Operator overloading
	Vector2 operator+(const Vector2&);
	Vector2 operator-(const Vector2&);
	Vector2 operator+=(const Vector2&);
	Vector2 operator-=(const Vector2&);
	Vector2 operator/(const float&);
	Vector2 operator*(const float&);
	friend std::ostream& operator<<(std::ostream&, const Vector2&);

	float _x;
	float _y;

private:
	
	//SFML
	sf::Vertex _line[2];
	
};
