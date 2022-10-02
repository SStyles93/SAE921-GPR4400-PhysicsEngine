#include <Graphics/SfmlUtilities.h>


namespace SFMLUtilities
{
    
    
    Vector2 pixelsToMeters(sf::Vector2f pixels)
    {
        return Vector2(pixels.x / pixelsMetersRatio, pixels.y / pixelsMetersRatio * -1.0f);
    }
    Vector2 pixelsToMeters(sf::Vector2u pixels)
    {
        return Vector2(pixels.x / pixelsMetersRatio, pixels.y / pixelsMetersRatio * -1.0f);
    }
    Vector2 pixelsToMeters(sf::Vector2i pixels)
    {
        return Vector2(pixels.x / pixelsMetersRatio, pixels.y / pixelsMetersRatio * -1.0f);
    }
    float pixelsToMeters(float pixels)
    {
        return pixels / pixelsMetersRatio;
    }
    
    sf::Vector2f metersToPixels(Vector2 meters)
    {
        return sf::Vector2f(meters.x * pixelsMetersRatio, -1.0f * meters.y * pixelsMetersRatio);
    }
    float metersToPixels(float meters) 
    {
        return meters * pixelsMetersRatio;
    }

    Vector2 SfmlToWorld(const sf::Vector2i vector2i, sf::RenderWindow& window)
    {
        Vector2 newPos = Vector2(vector2i.x / pixelsMetersRatio, -vector2i.y / pixelsMetersRatio);
        return newPos;
    }
    sf::Vector2f WorldToSfml(const Vector2 vector, sf::RenderWindow& window)
    {
        sf::Vector2f newPos = sf::Vector2f(vector.x * pixelsMetersRatio, -vector.y * pixelsMetersRatio);
        return newPos;
    }
}