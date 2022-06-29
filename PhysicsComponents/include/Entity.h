#pragma once
#include "SFML/Graphics.hpp"
#include "Rigidbody.h"
#include "Collider.h"
#include "SfmlUtilities.h"

class Entity : public sf::Drawable, public sf::Transformable
{

public:

	//Entity constructor
	Entity(std::unique_ptr<sf::Shape>);
	Entity(std::unique_ptr<sf::Shape>, std::unique_ptr<Rigidbody>);
	~Entity();

	Rigidbody* GetRigidbody();
	//sf::Vector2f Vector2Sf(const Vector2&);

	//Physical Update
	void Update(sf::RenderWindow&);
	//Drawing Method
	void draw(sf::RenderTarget&, sf::RenderStates) const override;


private:

	std::unique_ptr<sf::Shape> _shape;
	std::unique_ptr<Rigidbody> _rigidbody;
};
