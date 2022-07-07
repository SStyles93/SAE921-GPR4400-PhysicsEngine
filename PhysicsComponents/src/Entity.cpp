#include "Entity.h"


Entity::Entity(std::unique_ptr<sf::Shape> shape) : _shape(std::move(shape)){}
Entity::Entity(std::unique_ptr<sf::Shape> shape, std::unique_ptr<Rigidbody> rigidbody) : _shape(std::move(shape)), _rigidbody(std::move(rigidbody)){}
Entity::~Entity() = default;

Rigidbody* Entity::GetRigidbody() 
{
	return _rigidbody.get();
}

void Entity::Update(sf::RenderWindow& window) 
{
	setPosition(SFMLUtilities::WorldToSfml(_rigidbody->GetPosition(), window));
}
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (_rigidbody != nullptr) 
	{
		if (_rigidbody->GetCollider()->IsColliding()) 
		{
			//Color
			sf::Color color = sf::Color(0, 255, 0, 255);
			_shape->setFillColor(color);
		}
		else
		{
			sf::Color color = sf::Color(255, 255, 255, 255);
			_shape->setFillColor(color);
		}
	}

	states.transform *= getTransform();
	target.draw(*_shape, states);
}