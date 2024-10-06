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
	void renderFood(sf::RenderTarget& target);

	const sf::FloatRect getFoodBounds() const;

	//Constructor & Destructor
	Food(sf::RenderWindow* win);
	~Food();

private:
	//Private functions

	sf::RectangleShape foodShape;
};

