#pragma once
#include "Player.h"
#include "Food.h"
#include <iostream>
#include <map>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

/*
This class is used as the "Game Engine". Everything is happening here
*/

/*
TODO
- set screen bounds for snake movement
- Add a main menu
*/

class Game
{
	public:
	//public functions
	void updateEvents();
	void Update();
	void Render();


	//bool for checking if the window is runing
	const bool isRunning() const;

	//Constructor & Destructor
	Game();
	~Game();

	private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::Time deltaTime;

	//Player and food objects
	Player* player;
	Food* foodObj;
	bool isPlayerDead;
	
	//private functions
	void InitVariables();
	void InitWindow();
	void updateFood();
};

