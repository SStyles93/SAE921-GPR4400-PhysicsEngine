#pragma once
#include <iostream>
#include <string>

class Vector2
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

};

//std::iostream operator<<(std::iostream&, const Vector2&);

