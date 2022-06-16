#include "Vector2.h"

Vector2::Vector2(const float x, const float y) : _x(x), _y(y) 
{
	_line[0] = sf::Vector2(0.0f, 0.0f);
	_line[1] = sf::Vector2(_x, _y);
}
Vector2::~Vector2() {}

/// <summary>
/// Magnitude of this Vector
/// </summary>
/// <returns>The Magnitude</returns>
float Vector2::Magnitude() 
{
	return std::sqrtf((_x * _x) + (_y * _y));
};

/// <summary>
/// SquaredMagnitude of this Vector
/// </summary>
/// <returns>The Squared Magnitude</returns>
float Vector2::SqrMagnitude() 
{
	return (_x * _x) + (_y * _y);
};

/// <summary>
/// Gives the Dot product of this vector and the given one in parameter
/// </summary>
/// <param name="v1">Vector used for the dot product</param>
/// <returns>The Dot Product of the two given Vectors</returns>
float Vector2::Dot(const Vector2& v1)
{
	return ((this->_x * v1._x) * (this->_x * v1._y)) + ((this->_y * v1._x) * (this->_y * v1._y));
}

/// <summary>
/// Normalizes this Vector
/// </summary>
/// <returns>The Normalized Vector</returns>
Vector2 Vector2::Normalized() 
{
	return Vector2(_x / Magnitude(), _y / Magnitude());
}

/// <summary>
/// Sets the origin of the Vector2
/// </summary>
/// <param name="origin">Vector2 origin of the vector</param>
void Vector2::SetOrigin(const Vector2& origin) 
{
	_line[0] = sf::Vector2(origin._x, origin._y);
}

//void Vector2::draw(sf::RenderTarget& target, sf::RenderStates states) const 
//{
//	states.transform *= getTransform();
//	target.draw(_line, 2, sf::Lines);
//}

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

std::ostream& operator<<(std::ostream& os, const Vector2& vec) 
{
	os << vec._x << '|' << vec._y << "\n";
	return os;
}