#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Body
{
public:
	//Public functions
	void renderBody(sf::RenderTarget& target);
	void moveBody(float posX, float posY);

	//Constructor & Destructor
	Body();
	~Body();

private:
	//Private parameters
	float movementSpeed;
	sf::RectangleShape bodyShape;
};

