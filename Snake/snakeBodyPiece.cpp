#include "snakeBodyPiece.h"

//Constructor
snakeBodyPiece::snakeBodyPiece()
{
    this->setSize(sf::Vector2f(60, 60)); //Setting the size of the snake body piece
    this->setFillColor(sf::Color::Green); //Setting the color of the snake body piece
}

//Destructor
snakeBodyPiece::~snakeBodyPiece()
{

}
const sf::FloatRect snakeBodyPiece::getBounds() const
{
    return this->getGlobalBounds();
}
