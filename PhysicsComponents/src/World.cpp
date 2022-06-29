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
	}

	return EXIT_SUCCESS;
}

void World::Init() 
{
    // Basic Setup of the window
    _window.create(sf::VideoMode(1280, 800), "PhysicsVisualiser");

    // Vertical sync, framerate
    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(60);
	
	//Create the physics engine
	_engine = std::make_unique<PhysicsEngine>();

	////Get the window center
	//_windowCenter = Vector2(_window.getSize().x * 0.5f, _window.getSize().y * -0.5f);
	//Vector2 worldPos = Vector2(_windowCenter / SFMLUtilities::pixelsMetersRatio);

	//std::unique_ptr<Entity> entity2 = std::make_unique<Entity>(std::make_unique<sf::CircleShape>(100.0f), std::make_unique<Rigidbody>());

	//entity2->GetRigidbody()->SetPosition(worldPos);
	//entity2->GetRigidbody()->SetMass(10.0f);
	//entity2->GetRigidbody()->SetGravityScale(0.0f);
	//entity2->GetRigidbody()->SetSphereCollider(std::make_unique<SphereCollider>(worldPos, 100.0f / SFMLUtilities::pixelsMetersRatio));

	////Register entities to the physics engine
	//_engine->RegisterRigidbody(entity2->GetRigidbody());
	////Register entity to the world
	//_entities.emplace_back(std::move(entity2));
}

/// <summary>
/// Adds an entity and the given position
/// </summary>
/// <param name="position">The position (Vector2i)</param>
void World::AddEntity(sf::Vector2i position) 
{
	Vector2 positionInMeters = Vector2(SFMLUtilities::sfmlToWorld(position, _window));


	//Create an entity
	std::unique_ptr<Entity> entity1 = std::make_unique<Entity>(std::make_unique<sf::CircleShape>(10.0f), std::make_unique<Rigidbody>());
	
	entity1->GetRigidbody()->SetPosition(positionInMeters);
	entity1->GetRigidbody()->SetMass(1.0f);
	entity1->GetRigidbody()->SetGravityScale(0.01f);
	entity1->GetRigidbody()->SetSphereCollider(std::make_unique<SphereCollider>(positionInMeters, 10.0f/ SFMLUtilities::pixelsMetersRatio));

	//Register entities to the physics engine
	_engine->RegisterRigidbody(entity1->GetRigidbody());
	//Register entity to the world
	_entities.emplace_back(std::move(entity1));
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

		if (event.type == sf::Event::KeyReleased)
		{
			
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
		{	
			AddEntity(sf::Mouse::getPosition(_window));
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