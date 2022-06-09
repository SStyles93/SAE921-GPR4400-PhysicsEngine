#pragma once
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Vector2 : public sf::Drawable, public sf::Transformable
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

	void draw(sf::RenderTarget&, sf::RenderStates) const override;

	//Operator overloading
	Vector2 operator+(const Vector2&);
	Vector2 operator-(const Vector2&);
	Vector2 operator+=(const Vector2&);
	Vector2 operator-=(const Vector2&);
	Vector2 operator/(const float&);
	Vector2 operator*(const float&);


private:

	float _x;
	float _y;
	
	//SFML
	sf::Vertex _line[2];
};

//std::iostream operator<<(std::iostream&, const Vector2&);

