#include "Player.h"

//Moving the player
void Player::playerMovement(sf::Vector2f &moveDirection)
{
		snakeTail->setPosition(snakeHead->getPosition() + moveDirection);
		snakeHead = snakeTail;
		++snakeTail;

		if (snakeTail == snakeBody.end())
		{
			snakeTail = snakeBody.begin();
		}


}

//Updating the player
void Player::updatePlayer(sf::Time dt, sf::RenderWindow* win)
{
	elapsedTime += dt;

	sf::Vector2f newSnakeDirection = snakeHead->getPosition();
	
	//General Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (elapsedTime.asSeconds() > 0.1f)
		{
			newSnakeDirection = { -65.f,0.f };
			this->playerMovement(newSnakeDirection); //The 60 means, that it will move by 60 pixels, which in this case is the "block" and food size
			elapsedTime = sf::Time::Zero;
			
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		if (elapsedTime.asSeconds() > 0.1f )
		{
			newSnakeDirection = { 65.f,0.f };
			this->playerMovement(newSnakeDirection); 
			elapsedTime = sf::Time::Zero;
			
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		if (elapsedTime.asSeconds() > 0.1f )
		{

			newSnakeDirection = { 0.f ,-65.f };
			this->playerMovement(newSnakeDirection);
			elapsedTime = sf::Time::Zero;

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		if (elapsedTime.asSeconds() > 0.1f )
		{

			newSnakeDirection = { 0.f ,65.f };
			this->playerMovement(newSnakeDirection);
			elapsedTime = sf::Time::Zero;
		}
	}
}

//Rendering the player
void Player::renderPlayer(sf::RenderTarget& target)
{
	//target.draw(this->playerShape);
	for (auto& piece : this->snakeBody)
	{
		target.draw(piece);
	}
}

//Function used for adding new blocks to the snake
void Player::growSnake()
{
	sf::RectangleShape newPiece;
	newPiece.setSize(sf::Vector2f(60, 60));
	newPiece.setFillColor(sf::Color::Green);
	newPiece.setPosition(snakeHead->getPosition());

	snakeHead = snakeBody.insert(++snakeHead, newPiece);
}

//Returns player bounds for collisions, etc.
const sf::FloatRect Player::getPlayerBounds() const
{
	return this->snakeHead->getGlobalBounds();
}

const sf::FloatRect Player::getBodyBounds() const
{
	for (auto& piece : this->snakeBody)
	{
		return piece.getGlobalBounds();
	}
}


//Initializing player variables
void Player::initVariavles()
{
	elapsedTime = sf::Time::Zero;
	this->score = 0;
	this->movementSpeed = 2.0f;
	float x = 65.f;
	for (auto& piece : this->snakeBody)
	{
		piece.setSize(sf::Vector2f(60, 60));
		piece.setFillColor(sf::Color::Green);
		piece.setPosition({x,65.f});
		x += 65;
	}
}

//Adding points to the player score
void Player::addScore(int points)
{
	this->score += points;
	std::cout << "Current score: " << this->score <<"\n";
}

//Constructor
Player::Player(sf::RenderWindow* win) : snakeBody(std::list<sf::RectangleShape>(4))
{
	snakeHead = --snakeBody.end();
	snakeTail = snakeBody.begin();
	this->initVariavles();
}

//Destructor
Player::~Player()
{
	
}