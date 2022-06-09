#include "Entity.h"

Entity::Entity(std::unique_ptr<sf::Drawable> drawable) : _drawable(std::move(drawable)){}

Entity::~Entity() = default;

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(*_drawable, states);
}