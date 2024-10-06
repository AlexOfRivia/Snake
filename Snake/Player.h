#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Player
{
public:
	//Public functions

	const sf::FloatRect playerBounds() const; //Returns player bounds

	//Constructor & Destructor
	Player(sf::RenderWindow* win);
	~Player();

private:
	//Private functions
	void initVariavles();
};

