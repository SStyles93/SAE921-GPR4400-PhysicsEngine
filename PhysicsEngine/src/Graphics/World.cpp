#include "Graphics/World.h"
typedef std::chrono::high_resolution_clock Clock;

int World::Loop() 
{
	while (_window.isOpen())
	{
		auto startTime = std::chrono::steady_clock::now();

		CheckEvents();
		FixedUpdate();
		Update();

		auto endTime = std::chrono::steady_clock::now();
		auto elapsed = endTime - startTime;
		//elapsed time is in nanoseconds / 1'000'000'000 for seconds
		_deltaTime = elapsed.count() / 1000000000.0f;

		////Use to check frame rate;
		//std::cout << _deltaTime << std::endl;
	}

	return EXIT_SUCCESS;
}

void World::Init() 
{
    // Basic Setup of the window
    _window.create(sf::VideoMode(3840, 2160), "PhysicsVisualiser");

    // Vertical sync, framerate
    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(60);
	
	//Create the physics engine
	_engine = std::make_unique<PhysicsEngine>();

	BinarySpacePartitioning bsp =
		BinarySpacePartitioning(
			SFMLUtilities::pixelsToMeters(_window.getSize()), 4);
	_engine->SetBSP(bsp);

	////Check BSP by uncommenting this area
	//for (size_t i = 0; i < 50; i++)
	//{
	//	AddCircleEntity(sf::Vector2i(_window.getPosition().x * 0.25f, _window.getPosition().y * 0.25f));
	//}
	//for (size_t i = 0; i < 50; i++)
	//{
	//	AddCircleEntity(sf::Vector2i(_window.getPosition().x * 0.25f, _window.getPosition().y * 0.75f));
	//}for (size_t i = 0; i < 50; i++)
	//{
	//	AddCircleEntity(sf::Vector2i(_window.getPosition().x * 0.75f, _window.getPosition().y * 0.25f));
	//}for (size_t i = 0; i < 50; i++)
	//{
	//	AddCircleEntity(sf::Vector2i(_window.getPosition().x * 0.75f, _window.getPosition().y * 0.755f));
	//}

	InitialiseTexts();

}
void World::CheckEvents()
{
	sf::Event event;

	_window.setKeyRepeatEnabled(false);

	while (_window.pollEvent(event))
	{
		// Windows events -------------------------------------------------------------------------------
		if (event.type == sf::Event::Closed)
		{
			//close Window
			_window.close();
			return;
		}
		if (event.type == sf::Event::Resized)
		{
			auto view = _window.getView();
			view.setSize(event.size.width, event.size.height);
			_window.setView(view);
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::W)
			{
				_engine->AddForce(Vector2(0.0f, 25.0f));
			}
			if (event.key.code == sf::Keyboard::S)
			{
				_engine->AddForce(Vector2(0.0f, -25.0f));
			}
			if (event.key.code == sf::Keyboard::A)
			{
				_engine->AddForce(Vector2(-25.0f, 0.0f));
			}
			if (event.key.code == sf::Keyboard::D)
			{
				_engine->AddForce(Vector2(25.0f, 0.0f));
			}
			if (event.key.code == sf::Keyboard::Space) 
			{
				//Switches the Kinematic State of Rigidbodies
				for (auto& entity : _entities) 
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
			}
			/*if (event.key.code == sf::Keyboard::Delete) 
			{
				for (auto& entity : _entities) 
				{
				}
			}*/
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
		{	
			AddCircleEntity(sf::Mouse::getPosition(_window));
			//AddBoxEntity(sf::Mouse::getPosition(_window));
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			//AddCircleEntity(sf::Mouse::getPosition(_window));
			AddBoxEntity(sf::Mouse::getPosition(_window));
		}
	}
}
void World::FixedUpdate() 
{
	_engine->PhysicsUpdate(_deltaTime);
}
void World::Update() 
{
	//clear all elements from background
	_window.clear();

	//Draw all entities
	for (auto& entity : _entities)
	{
		entity->Update(_window);
		_window.draw(*entity);
	}

	//Draw all texts
	for (auto& text : _texts) 
	{
		_window.draw(text);
	}
	// Display all elements
	_window.display();
}

void World::AddCircleEntity(sf::Vector2i position)
{
	Vector2 positionInMeters = Vector2(SFMLUtilities::SfmlToWorld(position, _window));

	//Creates a circle shape
	sf::CircleShape circle = sf::CircleShape(20.0f);
	circle.setOrigin(circle.getRadius(), circle.getRadius());

	//Create an entity
	std::unique_ptr<Entity> entity1 = std::make_unique<Entity>(std::make_unique<sf::CircleShape>(circle), std::make_unique<Rigidbody>());

	entity1->GetRigidbody()->SetPosition(positionInMeters);
	entity1->GetRigidbody()->SetMass(1.0f);
	entity1->GetRigidbody()->SetGravityScale(0.0f);
	entity1->GetRigidbody()->SetCollider(std::make_unique<SphereCollider>(positionInMeters, 20.0f / SFMLUtilities::pixelsMetersRatio));
	
	//Sets the bounciness of the entity
	//entity1->GetRigidbody()->SetBounciness(1.0f);

	////Sets the Rigibody to static
	//entity1->GetRigidbody()->IsKinematic(false);

	//Register entities to the physics engine
	_engine->RegisterRigidbody(entity1->GetRigidbody());
	//Register entity to the world
	_entities.emplace_back(std::move(entity1));
}
void World::AddBoxEntity(sf::Vector2i position)
{
	Vector2 positionInMeters = Vector2(SFMLUtilities::SfmlToWorld(position, _window));

	//Creates a box shape
	sf::RectangleShape box = sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
	box.setOrigin(box.getSize().x * 0.5f, box.getSize().y * 0.5f);

	//Create an entity
	std::unique_ptr<Entity> entity1 = std::make_unique<Entity>(std::make_unique<sf::RectangleShape>(box), std::make_unique<Rigidbody>());

	entity1->GetRigidbody()->SetPosition(positionInMeters);
	entity1->GetRigidbody()->SetMass(1.0f);
	entity1->GetRigidbody()->SetGravityScale(0.0f);
	entity1->GetRigidbody()->SetCollider(std::make_unique<BoxCollider>(positionInMeters, 50.0f / SFMLUtilities::pixelsMetersRatio));
	
	////Sets the bounciness of the entity
	//entity1->GetRigidbody()->SetBounciness(1.0f);

	////Sets the body to static
	//entity1->GetRigidbody()->IsKinematic(false);

	//Register entities to the physics engine
	_engine->RegisterRigidbody(entity1->GetRigidbody());
	//Register entity to the world
	_entities.emplace_back(std::move(entity1));
}

void World::InitialiseTexts() 
{
	//SFML Font loading
	_font.loadFromFile("data/font/RetroGaming.ttf");
	//SFML Text Initialisation
	sf::Text mouseBtnLeftText;
	mouseBtnLeftText.setFont(_font);
	mouseBtnLeftText.setFillColor(sf::Color::White);
	mouseBtnLeftText.setCharacterSize(50);
	mouseBtnLeftText.setString(sf::String("Mouse L : Add Circle Entity"));
	mouseBtnLeftText.setPosition(sf::Vector2f(_window.getSize().x * 0.0f, _window.getSize().y * 0.0f));
	_texts.emplace_back(mouseBtnLeftText);

	sf::Text mouseBtnRightText;
	mouseBtnRightText.setFont(_font);
	mouseBtnRightText.setFillColor(sf::Color::White);
	mouseBtnRightText.setCharacterSize(50);
	mouseBtnRightText.setString(sf::String("Mouse R : Add Square Entity"));
	mouseBtnRightText.setPosition(sf::Vector2f(_window.getSize().x * 0.0f, _window.getSize().y * 0.05f));
	_texts.emplace_back(mouseBtnRightText);

	sf::Text wBtnText;
	wBtnText.setFont(_font);
	wBtnText.setFillColor(sf::Color::White);
	wBtnText.setCharacterSize(50);
	wBtnText.setString(sf::String("[W] : Add Force Upwards"));
	wBtnText.setPosition(sf::Vector2f(_window.getSize().x * 0.0f, _window.getSize().y * 0.1f));
	_texts.emplace_back(wBtnText);

	sf::Text aBtnText;
	aBtnText.setFont(_font);
	aBtnText.setFillColor(sf::Color::White);
	aBtnText.setCharacterSize(50);
	aBtnText.setString(sf::String("[A] : Add Force Leftwards"));
	aBtnText.setPosition(sf::Vector2f(_window.getSize().x * 0.0f, _window.getSize().y * 0.15f));
	_texts.emplace_back(aBtnText);

	sf::Text sBtnText;
	sBtnText.setFont(_font);
	sBtnText.setFillColor(sf::Color::White);
	sBtnText.setCharacterSize(50);
	sBtnText.setString(sf::String("[S] : Add Force Downwards"));
	sBtnText.setPosition(sf::Vector2f(_window.getSize().x * 0.0f, _window.getSize().y * 0.2f));
	_texts.emplace_back(sBtnText);

	sf::Text dBtnText;
	dBtnText.setFont(_font);
	dBtnText.setFillColor(sf::Color::White);
	dBtnText.setCharacterSize(50);
	dBtnText.setString(sf::String("[D] : Add Force Rightwards"));
	dBtnText.setPosition(sf::Vector2f(_window.getSize().x * 0.0f, _window.getSize().y * 0.25f));
	_texts.emplace_back(dBtnText);

	sf::Text SpaceBtnText;
	SpaceBtnText.setFont(_font);
	SpaceBtnText.setFillColor(sf::Color::White);
	SpaceBtnText.setCharacterSize(50);
	SpaceBtnText.setString(sf::String("[Space] : Switch Kinematic State"));
	SpaceBtnText.setPosition(sf::Vector2f(_window.getSize().x * 0.0f, _window.getSize().y * 0.30f));
	_texts.emplace_back(SpaceBtnText);
}