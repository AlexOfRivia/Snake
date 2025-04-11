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

/*TODO
- Place food on a grid, so that it's perfect with the snake size etc (the food is 60 by 60)
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
	//Private parameters
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

