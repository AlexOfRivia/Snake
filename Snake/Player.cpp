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

void Player::updateMovement()
{
	sf::Vector2f newDirection = snakeDirection;

	//General Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		
			newDirection = { -65.f,0.f };
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		
			newDirection = { 65.f,0.f };
			
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		
			 newDirection = { 0.f ,-65.f };
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		
		newDirection = { 0.f ,65.f };
		
	}

	if (std::abs(snakeDirection.x) != std::abs(newDirection.x) || std::abs(snakeDirection.y) != std::abs(newDirection.y))
	{
		snakeDirection = newDirection;
	}

}

//This will return wether the head is colliding with the body
bool Player::isCollidingWithBody() const
{
	bool isColliding = false;

	for (auto block = snakeBody.begin(); block != snakeBody.end(); ++block )
	{
		if (snakeHead != block&& block->getGlobalBounds().intersects(snakeHead->getGlobalBounds()))
		{
			isColliding = true;

			if (isColliding)
			{
				break;
			}
		}
	}
	return isColliding;
}

//Updating the player
void Player::updatePlayer(sf::Time dt, sf::RenderWindow* win)
{
	elapsedTime += dt;
	this->updateMovement();
	if (elapsedTime.asSeconds() > 0.3 && isDead == false)
	{
		this->playerMovement(snakeDirection);
		elapsedTime = sf::Time::Zero;
	}
	if (isDead==false)
	{
		scoreText.setString("Score: " + std::to_string(score));
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
	target.draw(this->scoreText);
}


//Function used for adding new blocks to the snake
void Player::growSnake()
{
	sf::RectangleShape newPiece;
	newPiece.setSize(sf::Vector2f(60, 60));
	newPiece.setFillColor(sf::Color::Green);
	newPiece.setPosition(snakeTail->getPosition());

	snakeTail = snakeBody.insert(snakeTail++, newPiece);
}

void Player::gameOver()
{
	this->isDead = true;
	this->scoreText.setString("Game Over!");
	this->snakeDirection = {0.f,0.f};
}

//Returns player bounds for collisions, etc.
const sf::FloatRect Player::getPlayerBounds() const
{
	return this->snakeHead->getGlobalBounds();
}

//Initializing player variables
void Player::initVariavles()
{
	//Time and score
	elapsedTime = sf::Time::Zero;
	this->score = 0;

	//is player dead
	this->isDead = false;

	//Initializing Text
	font.loadFromFile("DePixelBreit.ttf");
	scoreText.setPosition(1750/2, 0.f);
	scoreText.setFont(font);
	scoreText.setCharacterSize(30);
	

	//Initializing snake body
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
Player::Player(sf::RenderWindow* win) : snakeBody(std::list<sf::RectangleShape>(4)), snakeDirection({ 65.f,0.f })
{
	snakeHead = --snakeBody.end();
	snakeTail = snakeBody.begin();
	this->initVariavles();
}

//Destructor
Player::~Player()
{
	
}