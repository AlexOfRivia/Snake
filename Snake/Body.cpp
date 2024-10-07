#include "Body.h"


//Rendering the body
void Body::renderBody(sf::RenderTarget& target)
{
	target.draw(this->bodyShape);
}

//Moving the body
void Body::moveBody(float posX, float posY)
{

}

//Constructor
Body::Body()
{
	this->movementSpeed = 2.5f;
	bodyShape.setSize(sf::Vector2f(60, 60));
	bodyShape.setFillColor(sf::Color::Green);
}

//Destructor
Body::~Body()
{

}
