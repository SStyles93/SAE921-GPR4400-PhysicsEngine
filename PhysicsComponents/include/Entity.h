#pragma once
#include "SFML/Graphics.hpp"
#include "Rigidbody.h"

class Entity : public sf::Drawable, public sf::Transformable
{

public:

	//Entity constructor
	Entity(std::unique_ptr<sf::Drawable>);
	Entity(std::unique_ptr<sf::Drawable>, std::unique_ptr<Rigidbody>);
	~Entity();

	Rigidbody* GetRigidbody();
	sf::Vector2f Vector2Sf(const Vector2&);

	//Physical Update
	void Update();
	//Drawing Method
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:

	std::unique_ptr<sf::Drawable> _drawable;
	std::unique_ptr<Rigidbody> _rigidbody;

};
