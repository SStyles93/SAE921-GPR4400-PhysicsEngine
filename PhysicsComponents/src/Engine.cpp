#include "Engine.h"

int Engine::Loop() 
{
	while (_window.isOpen())
	{
		CheckEvents();
		FixedUpdate();
		Update();

	}

	return EXIT_SUCCESS;
}

void Engine::Init() 
{
    // Basic Setup of the window
    _window.create(sf::VideoMode(800, 600), "PhysicsVisualiser");
    
    // Vertical sync, framerate
    _window.setVerticalSyncEnabled(true);
    _window.setFramerateLimit(30);

	std::unique_ptr<Entity> e2 = std::make_unique<Entity>(std::make_unique<sf::CircleShape>(50.0f));
	_entities.emplace_back(std::move(e2));

	std::unique_ptr<Entity> vec2 = std::make_unique<Entity>(std::make_unique<Vector2>(200.f,200.f));
	_entities.emplace_back(std::move(vec2));

	_entities.emplace_back(std::make_unique<Entity>(std::make_unique<Vector2>(100.0f, 10.0f)));

}

void Engine::CheckEvents()
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

void Engine::FixedUpdate() 
{

}

void Engine::Update() 
{
	//clear all elements from background
	_window.clear();

	//Draw something
	for (auto& entity : _entities)
	{
		_window.draw(*entity);
	}
	

	// Display all elements
	_window.display();
}