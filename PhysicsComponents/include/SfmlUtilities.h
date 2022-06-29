#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2.h"

namespace SFMLUtilities
{

#pragma region CONVERSION
	////
	////Vector2 pixelsToMeters(sf::Vector2f pixels);
	////Vector2 pixelsToMeters(sf::Vector2u pixels);
	////Vector2 pixelsToMeters(sf::Vector2i pixels);
	////float pixelsToMeters(float pixels);
	////sf::Vector2f metersToPixels(Vector2 meters);
	Vector2 sfmlToWorld(const sf::Vector2i, sf::RenderWindow&);
	sf::Vector2f worldToSfml(const Vector2, sf::RenderWindow&);
	//
	//static Vector2& sfmlToWorld(const sf::Vector2i&);
	//
#pragma endregion
//
	static constexpr float pixelsMetersRatio = 100.0f;
	constexpr float epsilon = 0.0001f;

}