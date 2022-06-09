#pragma once
#include "SFML/Graphics.hpp"

class Entity : public sf::Drawable, public sf::Transformable
{

public:

	//Entity constructor
	Entity(std::unique_ptr<sf::Drawable>);
	~Entity();

	//Drawing Method
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	//Physical Update
	void FixedUpdate();

private:

	std::unique_ptr<sf::Drawable> _drawable;

};
