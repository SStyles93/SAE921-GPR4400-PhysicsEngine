#include "Entity.h"

/// <summary>
/// Drawable constructor
/// </summary>
/// <param name="drawable">The drawable object</param>
Entity::Entity(std::unique_ptr<sf::Drawable> drawable) : _drawable(std::move(drawable)){}
/// <summary>
/// Drawable & Rigidbody constructor
/// </summary>
/// <param name="drawable">The drawable object</param>
/// <param name="rigidbody">The rigidbody object</param>
Entity::Entity(std::unique_ptr<sf::Drawable> drawable, std::unique_ptr<Rigidbody> rigidbody) : _drawable(std::move(drawable)), _rigidbody(std::move(rigidbody)){}

Entity::~Entity() = default;

/// <summary>
/// Get the rigidbody from the entity
/// </summary>
/// <returns>Rigidbody</returns>
Rigidbody* Entity::GetRigidbody() 
{
	return _rigidbody.get();
}

/// <summary>
/// Converts a Vector2 to a sf::Vector2f
/// </summary>
/// <param name="vec">Vector2</param>
/// <returns>sf:Vector2f</returns>
sf::Vector2f Entity::Vector2Sf(const Vector2& vec) 
{
	return sf::Vector2f(vec._x, vec._y * -1.0f);
}

/// <summary>
/// Updates the graphical position of the Entity
/// </summary>
void Entity::Update() 
{
	setPosition(Vector2Sf(_rigidbody->GetPosition()));
}

/// <summary>
/// Draws the Entity
/// </summary>
/// <param name="target">RenderTarget</param>
/// <param name="states">RenderState</param>
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(*_drawable, states);
}