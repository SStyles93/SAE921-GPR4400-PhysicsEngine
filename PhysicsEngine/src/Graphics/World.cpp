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

		//Uncomment to check frame rate;
		//std::cout << _deltaTime << std::endl;
		_texts[11].setString(sf::String("FPS : " + std::to_string((CLOCKS_PER_SEC/_deltaTime)/1000)));
		_texts[12].setString(sf::String("Entity Count : " + std::to_string(_entities.size())));
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

	//BinarySpacePartitioning bsp =
	//	/*BinarySpacePartitioning(
	//		SFMLUtilities::pixelsToMeters(_window.getSize()), 4);*/
	//	BinarySpacePartitioning(Vector2(1620, 1080), 4);
	//_engine->SetBSP(bsp);

	////Check BSP by uncommenting this area
	//for (size_t i = 0; i < 100; i++)
	//{
	//	AddCircleEntity(sf::Vector2i(_window.getSize().x * 0.25f, _window.getSize().y * 0.25f));
	//}
	//for (size_t i = 0; i < 100; i++)
	//{
	//	AddCircleEntity(sf::Vector2i(_window.getSize().x * 0.25f, _window.getSize().y * 0.75f));
	//}for (size_t i = 0; i < 100; i++)
	//{
	//	AddCircleEntity(sf::Vector2i(_window.getSize().x * 0.75f, _window.getSize().y * 0.25f));
	//}for (size_t i = 0; i < 100; i++)
	//{
	//	AddCircleEntity(sf::Vector2i(_window.getSize().x * 0.75f, _window.getSize().y * 0.755f));
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

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			AddCircleEntity(sf::Mouse::getPosition(_window));
			_texts.at(1).setFillColor(sf::Color::Green);
		}
		else
		{
			_texts.at(1).setFillColor(sf::Color::White);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			AddBoxEntity(sf::Mouse::getPosition(_window));
			_texts.at(2).setFillColor(sf::Color::Green);
		}
		else
		{
			_texts.at(2).setFillColor(sf::Color::White);
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::W)
			{
				_engine->AddForce(Vector2(0.0f, 25.0f));
				_texts.at(3).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::A)
			{
				_engine->AddForce(Vector2(-25.0f, 0.0f));
				_texts.at(4).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::S)
			{
				_engine->AddForce(Vector2(0.0f, -25.0f));
				_texts.at(5).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::D)
			{
				_engine->AddForce(Vector2(25.0f, 0.0f));
				_texts.at(6).setFillColor(sf::Color::Green);
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
				_texts.at(7).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::Delete) 
			{
				Clear();
				_texts.at(8).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::Num1) 
			{
				_engine->SetGravity(_engine->GetGravity() + Vector2(0.0f, -1.00f));
				_texts[0].setString(sf::String("Gravity : ") + sf::String(_engine->GetGravity().ToString()));
				_texts.at(0).setFillColor(sf::Color::Green);
				_texts.at(9).setFillColor(sf::Color::Green);
			}
			if (event.key.code == sf::Keyboard::Num2) 
			{
				_engine->SetGravity(_engine->GetGravity() + Vector2(0.0f, 1.00f));
				_texts[0].setString(sf::String("Gravity : ") + sf::String(_engine->GetGravity().ToString()));
				_texts.at(0).setFillColor(sf::Color::Green);
				_texts.at(10).setFillColor(sf::Color::Green);
			}

		}
		else if(event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::W)
			{
				_texts.at(3).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::A)
			{
				_texts.at(4).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::S)
			{
				_texts.at(5).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::D)
			{
				_texts.at(6).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::Space)
			{
				_texts.at(7).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::Delete)
			{
				_texts.at(8).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::Num1)
			{
				_texts.at(9).setFillColor(sf::Color::White);
				_texts.at(0).setFillColor(sf::Color::White);
			}
			if (event.key.code == sf::Keyboard::Num2)
			{
				_texts.at(10).setFillColor(sf::Color::White);
				_texts.at(0).setFillColor(sf::Color::White);
			}
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
	
	/*std::vector<sf::RectangleShape> bspShapes;
	for (size_t i = 0; i < _engine->GetBSP().GetPositions().size(); i++)
	{
		bspShapes.push_back(sf::RectangleShape(sf::Vector2f(_window.getSize().x / 2.f, _window.getSize().y / 2.f)));
		bspShapes[i].setPosition(_engine->GetBSP().GetPositions()[i].first, _engine->GetBSP().GetPositions()[i].second);
		bspShapes[i].setOutlineColor(sf::Color::Cyan);
		bspShapes[i].setOutlineThickness(0.5f);
	}
	for (auto& shapes : bspShapes) 
	{
		_window.draw(shapes);
	}*/

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
	entity1->GetRigidbody()->SetGravityScale(1.0f);
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
	entity1->GetRigidbody()->SetGravityScale(1.0f);
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
void World::Clear() 
{
	_entities.clear();
	_engine->Clear();
	_engine->SetGravity(Vector2(0.0f, 0.0f));
	_texts[0].setString(sf::String("Gravity : ") + sf::String(_engine->GetGravity().ToString()));
}

void World::InitialiseTexts() 
{
	//SFML Font loading
	_font.loadFromFile("data/font/RetroGaming.ttf");

	//SFML Text Initialisation
	sf::Text gravityText;
	gravityText.setFont(_font);
	gravityText.setFillColor(sf::Color::White);
	gravityText.setCharacterSize(50);
	gravityText.setString(sf::String("Gravity : ") + sf::String(_engine->GetGravity().ToString()));
	gravityText.setPosition(sf::Vector2f(_window.getSize().x * 0.4f, _window.getSize().y * 0.0f));
	_texts.emplace_back(gravityText);

	sf::Text mouseBtnLeftText;
	mouseBtnLeftText.setFont(_font);
	mouseBtnLeftText.setFillColor(sf::Color::White);
	mouseBtnLeftText.setCharacterSize(50);
	mouseBtnLeftText.setString(sf::String("Mouse [L] : Add Circle Entity"));
	mouseBtnLeftText.setPosition(sf::Vector2f(_window.getSize().x * 0.0f, _window.getSize().y * 0.0f));
	_texts.emplace_back(mouseBtnLeftText);

	sf::Text mouseBtnRightText;
	mouseBtnRightText.setFont(_font);
	mouseBtnRightText.setFillColor(sf::Color::White);
	mouseBtnRightText.setCharacterSize(50);
	mouseBtnRightText.setString(sf::String("Mouse [R] : Add Square Entity"));
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

	sf::Text spaceBtnText;
	spaceBtnText.setFont(_font);
	spaceBtnText.setFillColor(sf::Color::White);
	spaceBtnText.setCharacterSize(50);
	spaceBtnText.setString(sf::String("[Space] : Switch Kinematic State"));
	spaceBtnText.setPosition(sf::Vector2f(_window.getSize().x * 0.0f, _window.getSize().y * 0.30f));
	_texts.emplace_back(spaceBtnText);

	sf::Text deleteBtnText;
	deleteBtnText.setFont(_font);
	deleteBtnText.setFillColor(sf::Color::White);
	deleteBtnText.setCharacterSize(50);
	deleteBtnText.setString(sf::String("[Del] : Clear world"));
	deleteBtnText.setPosition(sf::Vector2f(_window.getSize().x * 0.0f, _window.getSize().y * 0.35f));
	_texts.emplace_back(deleteBtnText);
	
	sf::Text num1BtnText;
	num1BtnText.setFont(_font);
	num1BtnText.setFillColor(sf::Color::White);
	num1BtnText.setCharacterSize(50);
	num1BtnText.setString(sf::String("[1] : Gravity -1 (Downwards)"));
	num1BtnText.setPosition(sf::Vector2f(_window.getSize().x * 0.0f, _window.getSize().y * 0.8f));
	_texts.emplace_back(num1BtnText);
	
	sf::Text num2BtnText;
	num2BtnText.setFont(_font);
	num2BtnText.setFillColor(sf::Color::White);
	num2BtnText.setCharacterSize(50);
	num2BtnText.setString(sf::String("[2] : Gravity +1 (Upwards)"));
	num2BtnText.setPosition(sf::Vector2f(_window.getSize().x * 0.0f, _window.getSize().y * 0.85f));
	_texts.emplace_back(num2BtnText);

	sf::Text frameRateText;
	frameRateText.setFont(_font);
	frameRateText.setFillColor(sf::Color::White);
	frameRateText.setCharacterSize(50);
	frameRateText.setString(sf::String("FPS : " + std::to_string(CLOCKS_PER_SEC/_deltaTime)));
	frameRateText.setPosition(sf::Vector2f(_window.getSize().x * 0.8f, _window.getSize().y * 0.0f));
	_texts.emplace_back(frameRateText);

	sf::Text entityCount;
	entityCount.setFont(_font);
	entityCount.setFillColor(sf::Color::White);
	entityCount.setCharacterSize(50);
	entityCount.setString(sf::String("Entity Count : " + std::to_string(_entities.size())));
	entityCount.setPosition(sf::Vector2f(_window.getSize().x * 0.8f, _window.getSize().y * 0.1f));
	_texts.emplace_back(entityCount);
}