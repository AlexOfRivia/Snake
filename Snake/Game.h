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

	Player* player;

	//private functions
	void InitVariables();
	void InitWindow();
};

