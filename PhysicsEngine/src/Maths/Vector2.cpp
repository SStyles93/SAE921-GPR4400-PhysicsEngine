#include "Maths/Vector2.h"

Vector2::Vector2() = default;
Vector2::Vector2(const float x, const float y) : x(x), y(y) {}

float Vector2::Magnitude() const
{
	return std::sqrtf((x * x) + (y * y));
};
float Vector2::SqrMagnitude() const
{
	return (x * x) + (y * y);
};
float Vector2::Dot(const Vector2& v1) const
{
	return (x * v1.x)  + (y * v1.y);
}
Vector2 Vector2::Normalized() const
{
	if (Magnitude() <= 0.0f) 
	{
		return Vector2{ 0.0f, 0.0f };
	}
	return Vector2{ x / Magnitude(), y / Magnitude() };
}
Vector2 Vector2::RightOrtho() 
{
	return Vector2{ y, -x };
}
Vector2 Vector2::LeftOrtho()
{
	return Vector2{ -y, x };
}

void Vector2::SetOrigin(const Vector2& origin){}

std::string Vector2::ToString() const
{
	return std::string(std::to_string(x) + " , " + std::to_string(y));
}

Vector2 Vector2::operator+(const Vector2& v1) const
{
	return Vector2{ x + v1.x, y + v1.y };
}
Vector2 Vector2::operator-(const Vector2& v1) const
{
	return Vector2{x - v1.x, y - v1.y};
}
Vector2 Vector2::operator+=(const Vector2& v1)
{
	x = x + v1.x;
	y = y + v1.y;

	return *this;
}
Vector2 Vector2::operator-=(const Vector2& v1)
{
	x = x - v1.x;
	y = y - v1.y;

	return *this;
}
Vector2 Vector2::operator*(const float& f) const
{
	return Vector2{ x * f, y * f };
}
Vector2 Vector2::operator/(const float& f) const
{
	return Vector2{ x / f, y / f };
}
std::ostream& operator<<(std::ostream& os, const Vector2& vec)
{
	os << vec.x << '|' << vec.y << "\n";
	return os;
}