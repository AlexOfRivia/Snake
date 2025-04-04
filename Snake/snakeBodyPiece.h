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
	const sf::FloatRect getBounds() const;
};

