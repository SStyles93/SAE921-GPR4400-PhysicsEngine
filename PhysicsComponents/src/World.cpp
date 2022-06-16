#include "World.h"

int World::Loop() 
{
	while (_window.isOpen())
	{
		
		CheckEvents();
		FixedUpdate();
		Update();

	}

	return EXIT_SUCCESS;
}

void World::Init() 
{
    // Basic Setup of the window
    _window.create(sf::VideoMode(1920, 1080), "PhysicsVisualiser");

    // Vertical sync, framerate
    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(30);
	
	//Get the window center
	Vector2 windowCenter = Vector2(_window.getSize().x * 0.5f, _window.getSize().y * 0.5f);

	//Create an entity
	std::unique_ptr<Entity> vec2 = std::make_unique<Entity>(std::make_unique<sf::CircleShape>(100.0f), std::make_unique<Rigidbody>());
	vec2->GetRigidbody()->SetPosition(windowCenter);
	vec2->GetRigidbody()->SetMass(1.0f);

	//Register entity to the world
	_entities.emplace_back(std::move(vec2));

	//Create the physics engine
	_engine = std::make_unique<PhysicsEngine>();

	//Register entities to the physics engine
	for (size_t i = 0; i < _entities.size(); i++)
	{
		_engine->RegisterRigidbody(_entities[i]->GetRigidbody());
	}
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
			//DO SOMETHING
		}
	}
}


/// <summary>
/// The physics update of the engine
/// </summary>
void World::FixedUpdate() 
{
	_engine->PhysicsUpdate();
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
		entity->Update();
		_window.draw(*entity);
	}

	// Display all elements
	_window.display();
}

void World::SetTime(const time_t& time) 
{
	_time = time;
}

void World::SetDeltaTime(const time_t& deltaTime) 
{
	_deltaTime = deltaTime;
}