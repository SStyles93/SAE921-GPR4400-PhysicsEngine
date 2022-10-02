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
	void FixedUpdate() const;
	/// <summary>
	/// The visual update of the world
	/// </summary>
	void Update();

	/// <summary>
	/// Adds an entity and the given position
	/// </summary>
	/// <param name="position">The position (Vector2i)</param>
	void AddCircleEntity(sf::Vector2i position);

	void Clear();

private:

	//SFML 
	//RenderWindow
	sf::RenderWindow window_;
	Vector2 windowCenter_{0,0};
	//Font
	sf::Font _font;
	//Texts
	std::vector<sf::Text> texts_;

	//Entities
	std::vector<std::unique_ptr<Entity>> entities_;

	//Physics
	std::unique_ptr<PhysicsEngine> engine_;

	//Time values
	std::chrono::steady_clock::time_point previousTime_;
	float deltaTime_ = 0;

	/// <summary>
	/// Initialises the texts to display in window_
	/// </summary>
	void InitialiseTexts();
};