#pragma once
#include "SFML/Graphics.hpp"
#include "Physics/Rigidbody.h"

class Entity : public sf::Drawable, public sf::Transformable
{

public:

	/// <summary>
	/// Drawable constructor
	/// </summary>
	/// <param name="shape">The drawable object</param>
	explicit Entity(std::unique_ptr<sf::Shape> shape);
	/// <summary>
	/// Drawable & Rigidbody constructor
	/// </summary>
	/// <param name="shape">The drawable object</param>
	/// <param name="rigidbody">The rigidbody object</param>
	explicit Entity(std::unique_ptr<sf::Shape> shape, std::unique_ptr<Rigidbody> rigidbody);

	/// <summary>
	/// Get the rigidbody from the entity
	/// </summary>
	/// <returns>Rigidbody</returns>
	Rigidbody* GetRigidbody();

	/// <summary>
	/// Updates the graphical position of the Entity
	/// </summary>
	/// <param name="window">The SFML window on which to render</param>
	void Update(sf::RenderWindow& window);
	/// <summary>
	/// Draws the Entity
	/// </summary>
	/// <param name="target">RenderTarget</param>
	/// <param name="states">RenderState</param>
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:

	std::unique_ptr<sf::Shape> shape_;
	std::unique_ptr<Rigidbody> rigidbody_;
};
