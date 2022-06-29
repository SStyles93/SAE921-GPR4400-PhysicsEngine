#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

struct Vector2 /*: public sf::Drawable, public sf::Transformable*/
{
public:

	//Default constructor && destructor
	Vector2();
	~Vector2();
	
	//Constructor
	Vector2(const float, const float);

	//Methods
	float Magnitude();
	float SqrMagnitude();
	float Dot(const Vector2&);
	Vector2 Normalized();
	Vector2 RightOrtho();
	Vector2 LeftOrtho();

	void SetOrigin(const Vector2&);
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
