#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Vector.h"

class Engine 
{
public:
	
	int Loop();

	void Init();
	void CheckEvents();
	void FixedUpdate();
	void Update();

private:

	//SFML renderWindow
	sf::RenderWindow _window;

	//Entities
	std::vector<std::unique_ptr<Entity>> _entities;
};