#include "Food.h"


//Rendering food object on screen
void Food::renderFood(sf::RenderTarget& target)
{
	target.draw(this->foodShape);
}

//Changing food location 
void Food::moveFood(float posX, float posY)
{
	this->foodShape.setPosition(posX,posY);
}

//Getting food bounds
const sf::FloatRect Food::getFoodBounds() const
{
	return this->foodShape.getGlobalBounds();
}

//constructor
Food::Food(sf::RenderWindow* win, float posX, float posY)
{
	this->foodShape.setSize(sf::Vector2f(60, 60)); //Setting food size
	this->foodShape.setFillColor(sf::Color::Red); //Setting food color
	this->foodShape.setPosition(posX,posY); //Setting food position
}

//Destructor
Food::~Food()
{

}