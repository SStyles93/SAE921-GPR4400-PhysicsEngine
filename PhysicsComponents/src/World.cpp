#include "World.h"
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
    _window.create(sf::VideoMode(1920, 1080), "PhysicsVisualiser");

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
	/*for (size_t i = 0; i < 50; i++)
	{
		AddCircleEntity(sf::Vector2i(_window.getPosition().x * 0.25f, _window.getPosition().y * 0.25f));
	}
	for (size_t i = 0; i < 50; i++)
	{
		AddCircleEntity(sf::Vector2i(_window.getPosition().x * 0.25f, _window.getPosition().y * 0.75f));
	}for (size_t i = 0; i < 50; i++)
	{
		AddCircleEntity(sf::Vector2i(_window.getPosition().x * 0.75f, _window.getPosition().y * 0.25f));
	}for (size_t i = 0; i < 50; i++)
	{
		AddCircleEntity(sf::Vector2i(_window.getPosition().x * 0.75f, _window.getPosition().y * 0.755f));
	}*/

}

/// <summary>
/// Looks for the user's interaction
/// </summary>
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
				_engine->AddForce(Vector2(0.0f, -9.81f));
			}
			if (event.key.code == sf::Keyboard::A)
			{
				_engine->AddForce(Vector2(-4.0f, 0.0f));
			}
			if (event.key.code == sf::Keyboard::D)
			{
				_engine->AddForce(Vector2(4.0f, 0.0f));
			}
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

/// <summary>
/// The physics update of the engine
/// </summary>
void World::FixedUpdate() 
{
	_engine->PhysicsUpdate(_deltaTime);
}

/// <summary>
/// The visual update of the world
/// </summary>
void World::Update() 
{
	//clear all elements from background
	_window.clear();

	//Draw something
	for (auto& entity : _entities)
	{
		entity->Update(_window);
		_window.draw(*entity);
	}

	// Display all elements
	_window.display();
}

/// <summary>
/// Adds an entity and the given position
/// </summary>
/// <param name="position">The position (Vector2i)</param>
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
	entity1->GetRigidbody()->SetBounciness(2.0f);
	
	////Sets the Rigibody to static
	//entity1->GetRigidbody()->IsKinematic(false);

	//Register entities to the physics engine
	_engine->RegisterRigidbody(entity1->GetRigidbody());
	//Register entity to the world
	_entities.emplace_back(std::move(entity1));
}

/// <summary>
/// Adds an entity and the given position
/// </summary>
/// <param name="position">The position (Vector2i)</param>
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

	//Sets the body to static
	entity1->GetRigidbody()->IsKinematic(false);

	//Register entities to the physics engine
	_engine->RegisterRigidbody(entity1->GetRigidbody());
	//Register entity to the world
	_entities.emplace_back(std::move(entity1));
}