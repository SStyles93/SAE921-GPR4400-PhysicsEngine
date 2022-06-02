#pragma once
#include <iostream>

class Vector
{
public:

	//Default constructor && destructor
	Vector();
	~Vector();
	
	//Constructor
	Vector(float, float);

	//Methods
	float Magnitude();
	float SqrMagnitude();

	Vector Normalized();

	//Operator overloading
	Vector operator+(Vector&);
	Vector operator-(Vector&);
	Vector operator*(float&);
	Vector operator/(float&);

private:
	float _x;
	float _y;
};
