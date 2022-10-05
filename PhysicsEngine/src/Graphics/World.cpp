#include "Graphics/World.h"
typedef std::chrono::high_resolution_clock Clock;

int World::Loop() 
{
	while (window_.isOpen())
	{
		auto startTime = std::chrono::steady_clock::now();

		CheckEvents();
		FixedUpdate();
		Update();

		auto endTime = std::chrono::steady_clock::now();
		auto elapsed = endTime - startTime;
		//elapsed time is in nanoseconds / 1'000'000'000 for seconds
		deltaTime_ = static_cast<float>(elapsed.count()) / 1000000000.0f;

		//Uncomment to check frame rate;
		//std::cout << deltaTime_ << std::endl;
		texts_[11].setString(sf::String("FPS : " + std::to_string((CLOCKS_PER_SEC/deltaTime_)/1000)));
		texts_[12].setString(sf::String("Entity Count : " + std::to_string(entities_.size())));
	}

	return EXIT_SUCCESS;
}

void World::Init() 
{
    // Basic Setup of the window
    window_.create(sf::VideoMode(3840, 2160), "PhysicsVisualiser");

    // Vertical sync, framerate
    window_.setVerticalSyncEnabled(true);
    window_.setFramerateLimit(60);
	
	//Create the physics engine
	engine_ = std::make_unique<PhysicsEngine>();

	//BinarySpacePartitioning bsp =
	//	/*BinarySpacePartitioning(
	//		SFMLUtilities::pixelsToMeters(window_.getSize()), 4);*/
	//	BinarySpacePartitioning(Vector2(1620, 1080), 4);
	//engine_->SetBSP(bsp);

	////Check BSP by uncommenting this area
	//for (size_t i = 0; i < 100; i++)
	//{
	//	AddCircleEntity(sf::Vector2i(window_.getSize().x * 0.25f, window_.getSize().y * 0.25f));
	//}
	//for (size_t i = 0; i < 100; i++)
	//{
	//	AddCircleEntity(sf::Vector2i(window_.getSize().x * 0.25f, window_.getSize().y * 0.75f));
	//}for (size_t i = 0; i < 100; i++)
	//{
	//	AddCircleEntity(sf::Vector2i(window_.getSize().x * 0.75f, window_.getSize().y * 0.25f));
	//}for (size_t i = 0; i < 100; i++)
	//{
	//	AddCircleEntity(sf::Vector2i(window_.getSize().x * 0.75f, window_.getSize().y * 0.755f));
	//}

	InitialiseTexts();

}
void World::CheckEvents()
{
	sf::Event event{};

	window_.setKeyRepeatEnabled(false);

	while (window_.pollEvent(event))
	{
		// Windows events -------------------------------------------------------------------------------
		if (event.type == sf::Event::Closed)
		{
			//close Window
			window_.close();
			return;
		}
		if (event.type == sf::Event::Resized)
		{
			auto view = window_.getView();
			view.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
			window_.setView(view);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			AddCircleEntity(sf::Mouse::getPosition(window_));
			texts_.at(1).setFillColor(sf::Color::Green);
		}
		else
		{
			texts_.at(1).setFillColor(sf::Color::White);
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::W)
			{
				engine_->AddForce(Vector2(0.0f, 25.0f));
				texts_.at(3).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::A)
			{
				engine_->AddForce(Vector2(-25.0f, 0.0f));
				texts_.at(4).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::S)
			{
				engine_->AddForce(Vector2(0.0f, -25.0f));
				texts_.at(5).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::D)
			{
				engine_->AddForce(Vector2(25.0f, 0.0f));
				texts_.at(6).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::Space) 
			{
				//Switches the Kinematic State of Rigidbodies
				for (auto& entity : entities_) 
				{
					if (entity->GetRigidbody()->IsStatic()) 
					{
						entity->GetRigidbody()->IsKinematic(true);
					}
					else
					{
						entity->GetRigidbody()->IsKinematic(false);
					}
				}
				texts_.at(7).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::Delete) 
			{
				Clear();
				texts_.at(8).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::Num1) 
			{
				engine_->SetGravity(engine_->GetGravity() + Vector2(0.0f, -1.00f));
				texts_[0].setString(sf::String("Gravity : ") + sf::String(engine_->GetGravity().ToString()));
				texts_.at(0).setFillColor(sf::Color::Green);
				texts_.at(9).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::Num2) 
			{
				engine_->SetGravity(engine_->GetGravity() + Vector2(0.0f, 1.00f));
				texts_[0].setString(sf::String("Gravity : ") + sf::String(engine_->GetGravity().ToString()));
				texts_.at(0).setFillColor(sf::Color::Green);
				texts_.at(10).setFillColor(sf::Color::Green);
			}

		}
		else if(event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::W)
			{
				texts_.at(3).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::A)
			{
				texts_.at(4).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::S)
			{
				texts_.at(5).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::D)
			{
				texts_.at(6).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::Space)
			{
				texts_.at(7).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::Delete)
			{
				texts_.at(8).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::Num1)
			{
				texts_.at(9).setFillColor(sf::Color::White);
				texts_.at(0).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::Num2)
			{
				texts_.at(10).setFillColor(sf::Color::White);
				texts_.at(0).setFillColor(sf::Color::White);
			}
		}
	}
}
void World::FixedUpdate() const
{
	engine_->PhysicsUpdate(deltaTime_);
}
void World::Update() 
{
	//clear all elements from background
	window_.clear();

	//Draw all entities
	for (auto& entity : entities_)
	{
		entity->Update(window_);
		window_.draw(*entity);
	}

	//Draw all texts
	for (auto& text : texts_) 
	{
		window_.draw(text);
	}
	
	/*std::vector<sf::RectangleShape> bspShapes;
	for (size_t i = 0; i < engine_->GetBSP().GetPositions().size(); i++)
	{
		bspShapes.push_back(sf::RectangleShape(sf::Vector2f(window_.getSize().x / 2.f, window_.getSize().y / 2.f)));
		bspShapes[i].setPosition(engine_->GetBSP().GetPositions()[i].first, engine_->GetBSP().GetPositions()[i].second);
		bspShapes[i].setOutlineColor(sf::Color::Cyan);
		bspShapes[i].setOutlineThickness(0.5f);
	}
	for (auto& shapes : bspShapes) 
	{
		window_.draw(shapes);
	}*/

	// Display all elements
	window_.display();
}

void World::AddCircleEntity(sf::Vector2i position)
{
	Vector2 positionInMeters = Vector2(SFMLUtilities::SfmlToWorld(position, window_));

	//Creates a circle shape
	sf::CircleShape circle = sf::CircleShape(20.0f);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	//Create an entity
	std::unique_ptr<Entity> entity1 = std::make_unique<Entity>(std::make_unique<sf::CircleShape>(circle), std::make_unique<Rigidbody>());

	entity1->GetRigidbody()->SetPosition(positionInMeters);
	entity1->GetRigidbody()->SetMass(1.0f);
	entity1->GetRigidbody()->SetGravityScale(1.0f);
	entity1->GetRigidbody()->SetCollider(std::make_unique<SphereCollider>(positionInMeters, 20.0f / SFMLUtilities::pixelsMetersRatio));
	
	//Sets the bounciness of the entity
	entity1->GetRigidbody()->SetBounciness(1.0f);

	////Sets the Rigibody to static
	//entity1->GetRigidbody()->IsKinematic(false);

	//Register entities to the physics engine
	engine_->RegisterRigidbody(entity1->GetRigidbody());
	//Register entity to the world
	entities_.emplace_back(std::move(entity1));
}
void World::Clear() 
{
	entities_.clear();
	engine_->Clear();
	engine_->SetGravity(Vector2(0.0f, 0.0f));
	texts_[0].setString(sf::String("Gravity : ") + sf::String(engine_->GetGravity().ToString()));
}
void World::InitialiseTexts() 
{
	//SFML Font loading
	_font.loadFromFile("data/font/RetroGaming.ttf");

	//SFML Text Initialisation
	sf::Text gravityText;
	gravityText.setFont(_font);
	gravityText.setFillColor(sf::Color::White);
	gravityText.setCharacterSize(50);
	gravityText.setString(sf::String("Gravity : ") + sf::String(engine_->GetGravity().ToString()));
	gravityText.setPosition(sf::Vector2f(static_cast<float>(window_.getSize().x * 0.4f), static_cast<float>(window_.getSize().y * 0.0f)));
	texts_.emplace_back(gravityText);

	sf::Text mouseBtnLeftText;
	mouseBtnLeftText.setFont(_font);
	mouseBtnLeftText.setFillColor(sf::Color::White);
	mouseBtnLeftText.setCharacterSize(50);
	mouseBtnLeftText.setString(sf::String("Mouse [L] : Add Circle Entity"));
	mouseBtnLeftText.setPosition(sf::Vector2f(static_cast<float>(window_.getSize().x * 0.0f), static_cast<float>(window_.getSize().y * 0.0f)));
	texts_.emplace_back(mouseBtnLeftText);

	sf::Text mouseBtnRightText;
	texts_.emplace_back(mouseBtnRightText);

	sf::Text wBtnText;
	wBtnText.setFont(_font);
	wBtnText.setFillColor(sf::Color::White);
	wBtnText.setCharacterSize(50);
	wBtnText.setString(sf::String("[W] : Add Force Upwards"));
	wBtnText.setPosition(sf::Vector2f(window_.getSize().x * 0.0f, window_.getSize().y * 0.1f));
	texts_.emplace_back(wBtnText);

	sf::Text aBtnText;
	aBtnText.setFont(_font);
	aBtnText.setFillColor(sf::Color::White);
	aBtnText.setCharacterSize(50);
	aBtnText.setString(sf::String("[A] : Add Force Leftwards"));
	aBtnText.setPosition(sf::Vector2f(window_.getSize().x * 0.0f, window_.getSize().y * 0.15f));
	texts_.emplace_back(aBtnText);

	sf::Text sBtnText;
	sBtnText.setFont(_font);
	sBtnText.setFillColor(sf::Color::White);
	sBtnText.setCharacterSize(50);
	sBtnText.setString(sf::String("[S] : Add Force Downwards"));
	sBtnText.setPosition(sf::Vector2f(window_.getSize().x * 0.0f, window_.getSize().y * 0.2f));
	texts_.emplace_back(sBtnText);

	sf::Text dBtnText;
	dBtnText.setFont(_font);
	dBtnText.setFillColor(sf::Color::White);
	dBtnText.setCharacterSize(50);
	dBtnText.setString(sf::String("[D] : Add Force Rightwards"));
	dBtnText.setPosition(sf::Vector2f(window_.getSize().x * 0.0f, window_.getSize().y * 0.25f));
	texts_.emplace_back(dBtnText);

	sf::Text spaceBtnText;
	spaceBtnText.setFont(_font);
	spaceBtnText.setFillColor(sf::Color::White);
	spaceBtnText.setCharacterSize(50);
	spaceBtnText.setString(sf::String("[Space] : Switch Kinematic State"));
	spaceBtnText.setPosition(sf::Vector2f(window_.getSize().x * 0.0f, window_.getSize().y * 0.30f));
	texts_.emplace_back(spaceBtnText);

	sf::Text deleteBtnText;
	deleteBtnText.setFont(_font);
	deleteBtnText.setFillColor(sf::Color::White);
	deleteBtnText.setCharacterSize(50);
	deleteBtnText.setString(sf::String("[Del] : Clear world"));
	deleteBtnText.setPosition(sf::Vector2f(window_.getSize().x * 0.0f, window_.getSize().y * 0.35f));
	texts_.emplace_back(deleteBtnText);
	
	sf::Text num1BtnText;
	num1BtnText.setFont(_font);
	num1BtnText.setFillColor(sf::Color::White);
	num1BtnText.setCharacterSize(50);
	num1BtnText.setString(sf::String("[1] : Gravity -1 (Downwards)"));
	num1BtnText.setPosition(sf::Vector2f(window_.getSize().x * 0.0f, window_.getSize().y * 0.8f));
	texts_.emplace_back(num1BtnText);
	
	sf::Text num2BtnText;
	num2BtnText.setFont(_font);
	num2BtnText.setFillColor(sf::Color::White);
	num2BtnText.setCharacterSize(50);
	num2BtnText.setString(sf::String("[2] : Gravity +1 (Upwards)"));
	num2BtnText.setPosition(sf::Vector2f(window_.getSize().x * 0.0f, window_.getSize().y * 0.85f));
	texts_.emplace_back(num2BtnText);

	sf::Text frameRateText;
	frameRateText.setFont(_font);
	frameRateText.setFillColor(sf::Color::White);
	frameRateText.setCharacterSize(50);
	frameRateText.setString(sf::String("FPS : " + std::to_string(CLOCKS_PER_SEC/deltaTime_)));
	frameRateText.setPosition(sf::Vector2f(window_.getSize().x * 0.8f, window_.getSize().y * 0.0f));
	texts_.emplace_back(frameRateText);

	sf::Text entityCount;
	entityCount.setFont(_font);
	entityCount.setFillColor(sf::Color::White);
	entityCount.setCharacterSize(50);
	entityCount.setString(sf::String("Entity Count : " + std::to_string(entities_.size())));
	entityCount.setPosition(sf::Vector2f(window_.getSize().x * 0.8f, window_.getSize().y * 0.1f));
	texts_.emplace_back(entityCount);
}