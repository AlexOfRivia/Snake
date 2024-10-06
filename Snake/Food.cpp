#include "Food.h"


//Rendering food object on screen
void Food::renderFood(sf::RenderTarget& target)
{
	target.draw(this->foodShape);
}

//Getting food bounds
const sf::FloatRect Food::getFoodBounds() const
{
	return this->foodShape.getGlobalBounds();
}

//constructor
Food::Food(sf::RenderWindow* win, float posX, float posY)
{
	this->foodShape.setSize(sf::Vector2f(60, 60));
	this->foodShape.setFillColor(sf::Color::Red);
	this->foodShape.setPosition(posX,posY);
}

//Destructor
Food::~Food()
{

}
