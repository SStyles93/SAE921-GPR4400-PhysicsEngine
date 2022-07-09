#pragma once
#include "SFML/Graphics.hpp"
#include "Maths/Vector2.h"

namespace SFMLUtilities
{

#pragma region CONVERSION
	
	Vector2 pixelsToMeters(sf::Vector2f pixels);
	Vector2 pixelsToMeters(sf::Vector2u pixels);
	Vector2 pixelsToMeters(sf::Vector2i pixels);
	float pixelsToMeters(float pixels);
	
	sf::Vector2f metersToPixels(Vector2 meters);

	Vector2 SfmlToWorld(const sf::Vector2i, sf::RenderWindow&);
	sf::Vector2f WorldToSfml(const Vector2, sf::RenderWindow&);

#pragma endregion

	static constexpr float pixelsMetersRatio = 100.0f;
	constexpr float epsilon = 0.0001f;

}