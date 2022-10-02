#include "Graphics/Entity.h"
#include "Graphics/SfmlUtilities.h"


Entity::Entity(std::unique_ptr<sf::Shape> shape) : shape_(std::move(shape)){}
Entity::Entity(std::unique_ptr<sf::Shape> shape, std::unique_ptr<Rigidbody> rigidbody) : shape_(std::move(shape)), rigidbody_(std::move(rigidbody)){}

Rigidbody* Entity::GetRigidbody() 
{
	return rigidbody_.get();
}

void Entity::Update(sf::RenderWindow& window) 
{
	setPosition(SFMLUtilities::WorldToSfml(rigidbody_->GetPosition(), window));
}
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (rigidbody_ != nullptr) 
	{
		if (rigidbody_->GetCollider()->IsColliding()) 
		{
			//Color
			sf::Color const greenColor = sf::Color(0, 255, 0, 255);
			shape_->setFillColor(greenColor);
			
		}
		else
		{
			sf::Color const color = sf::Color(255, 255, 255, 255);
			shape_->setFillColor(color);
		}

		if (rigidbody_->GetCollider()->IsOverlapping()) 
		{
			sf::Color const redColor = sf::Color(255, 0, 0, 255);
			shape_->setOutlineThickness(2.f);
			shape_->setOutlineColor(redColor);
		}
		else
		{
			shape_->setOutlineThickness(0.f);
		}
	}

	states.transform *= getTransform();
	target.draw(*shape_, states);
}