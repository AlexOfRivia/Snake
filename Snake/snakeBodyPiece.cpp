#include "snakeBodyPiece.h"

snakeBodyPiece::snakeBodyPiece()
{
	this->setSize(60, 60); //Setting the size of the snake body piece
	this->setFillColor(sf::Color::Green); //Setting the color of the snake body piece
}

const sf::FloatRect snakeBodyPiece::getBounds() const
{
	return this->getGlobalBounds();
}
