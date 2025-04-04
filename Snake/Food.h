#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Food : public sf::RectangleShape //Inheriting from sf::RectangleShape
{
public:
	//Public functions
	void renderFood(sf::RenderTarget& target);
	void moveFood(float posX, float posY);

	//Getting food bounds
	const sf::FloatRect getFoodBounds() const;

	//Constructor & Destructor
	Food(sf::RenderWindow* win, float posX, float posY);
	~Food();

};

