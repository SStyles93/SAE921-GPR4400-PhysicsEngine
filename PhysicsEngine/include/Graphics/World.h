#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include "Physics/PhysicsEngine.h"
#include "Entity.h"
#include "SfmlUtilities.h"

class World 
{
public:
	
	/// <summary>
	/// Loops through the different Updates
	/// </summary>
	/// <returns></returns>
	int Loop();

	/// <summary>
	/// Initialises all the elements used for the world
	/// </summary>
	void Init();
	/// <summary>
	/// Looks for the user's interaction
	/// </summary>
	void CheckEvents();
	/// <summary>
	/// The physics update of the engine
	/// </summary>
	void FixedUpdate();
	/// <summary>
	/// The visual update of the world
	/// </summary>
	void Update();

	/// <summary>
	/// Adds an entity and the given position
	/// </summary>
	/// <param name="position">The position (Vector2i)</param>
	void AddCircleEntity(sf::Vector2i position);
	/// <summary>
	/// Adds an entity and the given position
	/// </summary>
	/// <param name="position">The position (Vector2i)</param>
	void AddBoxEntity(sf::Vector2i position);

private:

	//SFML renderWindow
	sf::RenderWindow _window;
	Vector2 _windowCenter;

	//Entities
	std::vector<std::unique_ptr<Entity>> _entities;

	//Physics
	std::unique_ptr<PhysicsEngine> _engine;

	//Time values
	std::chrono::steady_clock::time_point previousTime;
	float _deltaTime = 0;
};