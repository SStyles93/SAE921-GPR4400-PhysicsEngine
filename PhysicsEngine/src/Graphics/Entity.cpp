#include "Graphics/Entity.h"


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
			sf::Color greenColor = sf::Color(0, 255, 0, 255);
			_shape->setFillColor(greenColor);
			
		}
		else
		{
			sf::Color color = sf::Color(255, 255, 255, 255);
			_shape->setFillColor(color);
		}

		if (_rigidbody->GetCollider()->IsOverlapping()) 
		{
			sf::Color redColor = sf::Color(255, 0, 0, 255);
			_shape->setOutlineThickness(2.f);
			_shape->setOutlineColor(redColor);
		}
		else
		{
			_shape->setOutlineThickness(0.f);
		}
	}

	states.transform *= getTransform();
	target.draw(*_shape, states);
}