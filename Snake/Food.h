#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Food
{
public:
	//Public functions

	//Constructor & Destructor
	Food();
	~Food();

private:
	//Private functions

	sf::RectangleShape foodShape;
};

