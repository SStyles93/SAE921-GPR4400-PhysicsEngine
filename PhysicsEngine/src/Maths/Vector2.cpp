#include "Maths/Vector2.h"

Vector2::Vector2(const float x, const float y) : _x(x), _y(y) 
{
	_line[0] = sf::Vector2(0.0f, 0.0f);
	_line[1] = sf::Vector2(_x, _y);
}
Vector2::Vector2() 
{
	_x = 0.0f;
	_y = 0.0f;
}
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
	return (_x * v1._x)  + (_y * v1._y);
}
Vector2 Vector2::Normalized() 
{
	if (Magnitude() <= 0.0f) 
	{
		return Vector2(0.0f, 0.0f);
	}
	return Vector2(_x / Magnitude(), _y / Magnitude());
}
Vector2 Vector2::RightOrtho() 
{
	return Vector2(_y, -_x);
}
Vector2 Vector2::LeftOrtho()
{
	return Vector2(-_y, _x);
}

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
	return Vector2(_x + v1._x, _y + v1._y);
}
Vector2 Vector2::operator-(const Vector2& v1) 
{
	return Vector2(_x - v1._x, _y - v1._y);
}
Vector2 Vector2::operator+=(const Vector2& v1) 
{
	_x = _x + v1._x;
	_y = _y + v1._y;

	return *this;
}
Vector2 Vector2::operator-=(const Vector2& v1)
{
	_x = _x - v1._x;
	_y = _y - v1._y;

	return *this;
}
Vector2 Vector2::operator*(const float& f)
{
	return Vector2(_x * f, _y * f);
}
Vector2 Vector2::operator/(const float& f)
{
	return Vector2(_x / f, _y / f);
}
std::ostream& operator<<(std::ostream& os, const Vector2& vec) 
{
	os << vec._x << '|' << vec._y << "\n";
	return os;
}