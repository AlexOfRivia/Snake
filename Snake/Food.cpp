#include "Food.h"


//Rendering food object on screen
void Food::renderFood(sf::RenderTarget& target)
{
	target.draw(*this);
}

//Changing food location 
void Food::moveFood(float posX, float posY)
{
	this->setPosition(posX,posY);
}

//Getting food bounds
const sf::FloatRect Food::getFoodBounds() const
{
	return this->getGlobalBounds();
}

//constructor
Food::Food(sf::RenderWindow* win, float posX, float posY)
{
	this->setSize(sf::Vector2f(60, 60)); //Setting food size
	this->setFillColor(sf::Color::Red); //Setting food color
	this->setPosition(posX,posY); //Setting food position
}

//Destructor
Food::~Food()
{

}