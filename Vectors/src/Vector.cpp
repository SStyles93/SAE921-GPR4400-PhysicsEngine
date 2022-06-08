#include <Vector.h>

Vector2::Vector2(const float x, const float y) : _x(x), _y(y) {}
Vector2::~Vector2() {}

float Vector2::Magnitude() 
{
	return std::sqrtf((_x * _x) + (_y * _y));
};

float Vector2::SqrMagnitude() 
{
	return (_x * _x) + (_y * _y);
};

float Vector2::Dot(const Vector2& v1)
{
	return ((this->_x * v1._x) * (this->_x * v1._y)) + ((this->_y * v1._x) * (this->_y * v1._y));
}

Vector2 Vector2::Normalized() 
{
	return Vector2(_x / Magnitude(), _y / Magnitude());
}

Vector2 Vector2::operator+(const Vector2& v1) 
{
	float _x = this -> _x + v1._x;
	float _y = this->_y + v1._y;

	return Vector2(_x, _y);
}

Vector2 Vector2::operator-(const Vector2& v1) 
{
	float _x = this->_x - v1._x;
	float _y = this->_y - v1._y;

	return Vector2(_x, _y);
}

Vector2 Vector2::operator+=(const Vector2& v1) 
{
	this->_x = this->_x + v1._x;
	this->_y = this->_y + v1._y;

	return Vector2(this->_x, this->_y);
}

Vector2 Vector2::operator-=(const Vector2& v1)
{
	this->_x = this->_x - v1._x;
	this->_y = this->_y - v1._y;

	return Vector2(this->_x, this->_y);
}

Vector2 Vector2::operator*(const float& f)
{
	return Vector2(this->_x * f, this->_y * f);
}

Vector2 Vector2::operator/(const float& f)
{
	return Vector2(this->_x / f, this->_y / f);
}

//std::iostream operator<<(const std::iostream stream, const Vector2& vec) 
//{
//
//}