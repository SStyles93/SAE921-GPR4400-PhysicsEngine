#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include "Entity.h"
#include "Vector2.h"
#include "Rigidbody.h"
#include "PhysicsEngine.h"

class World 
{
public:
	
	int Loop();

	void Init();
	void CheckEvents();
	void FixedUpdate();
	void Update();

	void SetTime(const time_t&);
	void SetDeltaTime(const time_t&);


private:

	//SFML renderWindow
	sf::RenderWindow _window;

	//Entities
	std::vector<std::unique_ptr<Entity>> _entities;

	//Physics
	std::unique_ptr<PhysicsEngine> _engine;

	//Time values
	time_t _time = 0;
	time_t _deltaTime = 0;
};