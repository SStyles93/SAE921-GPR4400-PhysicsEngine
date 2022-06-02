#include <Vector.h>


Vector::Vector(float x, float y) : _x(x), _y(y) {}
Vector::~Vector() {}

float Vector::Magnitude() 
{
	return std::sqrtf((_x * _x) + (_y * _y));
};

float Vector::SqrMagnitude() 
{
	return (_x * _x) + (_y * _y);
};

Vector Vector::Normalized() 
{
	return Vector(_x / Magnitude(), _y / Magnitude());
}

Vector Vector::operator+(Vector& v1) 
{
	float _x = this -> _x + v1._x;
	float _y = this->_y + v1._y;

	return Vector(_x, _y);
}

Vector Vector::operator-(Vector& v1) 
{
	float _x = this->_x - v1._x;
	float _y = this->_y - v1._y;

	return Vector(_x, _y);
}

Vector Vector::operator*(float& f)
{
	return Vector(this->_x * f, this->_y * f);
}

Vector Vector::operator/(float& f)
{
	return Vector(this->_x / f, this->_y / f);
}