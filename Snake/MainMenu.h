#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class MainMenu
{

public:
	void Update();
	void Render();

	//bool for checking if the window is runing
	const bool isMenuRunning() const;

private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::Time deltaTime;

	Game game;

	sf::Text gameText;
	sf::Text playText;
	sf::Font font;

};

