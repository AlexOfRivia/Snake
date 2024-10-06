#include "Player.h"

//Moving the player
void Player::playerMovement(const float& dirX, const float& dirY)
{
	this->playerShape.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

//Updating the player
void Player::updatePlayer(float dt, sf::RenderWindow* win)
{
	//General Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		this->playerMovement(-1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		this->playerMovement(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		this->playerMovement(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		this->playerMovement(0.f, 1.f);
	}
}

//Rendering the player
void Player::renderPlayer(sf::RenderTarget& target)
{
	target.draw(this->playerShape);
}

//Returns player bounds for collisions, etc.
const sf::FloatRect Player::getPlayerBounds() const
{
	return this->playerShape.getGlobalBounds();
}

//Initializing player variables
void Player::initVariavles()
{
	this->score = 0;
	this->movementSpeed = 2.5f;
	playerShape.setSize(sf::Vector2f(60,60));
	playerShape.setFillColor(sf::Color::Green);
}

//Adding points to the player score
void Player::addScore(int points)
{
	this->score += points;
	std::cout << "Current score: " << this->score <<"\n";
}

//Constructor
Player::Player(sf::RenderWindow* win)
{
	this->initVariavles();

}

//Destructor
Player::~Player()
{

}