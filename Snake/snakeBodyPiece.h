#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class snakeBodyPiece : public sf::RectangleShape
{
public:
	//Constructor & Destructor
	snakeBodyPiece();
	~snakeBodyPiece();
	//Public functions
	void setSize(float x, float y);
	void setColor(sf::Color color);
	void setPosition(float x, float y);
	const sf::FloatRect getBounds() const;
};

