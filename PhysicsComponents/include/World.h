#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include "Entity.h"
#include "Vector2.h"
#include "Rigidbody.h"
#include "PhysicsEngine.h"
#include "SphereCollider.h"
#include "SfmlUtilities.h"

class World 
{
public:
	
	int Loop();

	void Init();
	void CheckEvents();
	void FixedUpdate();
	void Update();

	void AddEntity(sf::Vector2i);

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