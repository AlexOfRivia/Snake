#include "Player.h"

//Moving the player
void Player::playerMovement(sf::Vector2f &moveDirection)
{
		snakeTail->setPosition(snakeHead->getPosition() + moveDirection); //Setting the position of the tail
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
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)))
	{
		newDirection = { -65.f,0.f };
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)))
	{
		newDirection = { 65.f,0.f };		
	} 
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)))
	{
		newDirection = { 0.f ,-65.f };
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)))
	{
		newDirection = { 0.f ,65.f };	
	}

	if (std::abs(snakeDirection.x) != std::abs(newDirection.x) || std::abs(snakeDirection.y) != std::abs(newDirection.y))
	{
		snakeDirection = newDirection;
	}

	//Screen Bounds Below

	//Right
	if (this->snakeHead->getPosition().x < 0)
	{
		this->snakeHead->setPosition(1920.f, this->snakeHead->getPosition().y);
	}

	//Down
	if (this->snakeHead->getPosition().y < 0)
	{
		this->snakeHead->setPosition(this->snakeHead->getPosition().x, 1080.f);
		
	}

	//Left
	if (this->snakeHead->getPosition().x + this->snakeHead->getGlobalBounds().width > 1985)
	{
		this->snakeHead->setPosition(0, this->snakeHead->getPosition().y);
		
	}

	//Up
	if (this->snakeHead->getPosition().y + this->snakeHead->getGlobalBounds().height > 1145)
	{
		this->snakeHead->setPosition(this->snakeHead->getPosition().x, 0);
	}

}

//This will return wether the head is colliding with the body
bool Player::isCollidingWithBody() const
{
	bool isColliding = false;

	for (auto block = snakeBody.begin(); block != snakeBody.end(); ++block )
	{
		if (snakeHead != block&& block->getGlobalBounds().intersects(snakeHead->getGlobalBounds())) //Checking if body is intersecting the head
		{
			isColliding = true;

			if (isColliding)
			{
				break; //Breaking upon collisiong
			}
		}
	}
	return isColliding; //Returning boolean
}


//Updating the player
void Player::updatePlayer(sf::Time dt, sf::RenderWindow* win)
{
	elapsedTime += dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
	{
		if (!isPKeyPressed) // Only toggle if the key was not already pressed
		{
			this->isPaused = !this->isPaused; // Toggle pause state
			isPKeyPressed = true; // Mark the key as pressed
		}
	}
	else
	{
		isPKeyPressed = false; // Reset the key state when released
	}
	this->updateMovement();
	if (elapsedTime.asSeconds() > 0.1 && isDead == false && isPaused==false) //Moving the snake in one direction automatically
	{
		this->playerMovement(snakeDirection);
		elapsedTime = sf::Time::Zero;
	}
	if (isDead==false)
	{
		this->scoreText.setString("Score: " + std::to_string(this->score));
		this->finalScoreText.setString("Score: " + std::to_string(this->score));
	}
	if (this->isPaused==true && this->isDead==false)
	{
		this->pausedText.setString("Game Paused! Press 'P' to unpause");
		this->pausedText.setPosition(500.f,500.f);
	}
	if (this->isPaused == false && this->isDead == false)
	{
		this->pausedText.setString("Game Paused! Press 'P' to unpause");
		this->pausedText.setPosition(100000.f, 100000.f);
	}
	if (this->isPaused==true && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
	{
		this->restartPlayer();
	}
}

//Rendering the player
void Player::renderPlayer(sf::RenderTarget& target)
{
	//target.draw(this->playerShape);
	for (auto& piece : this->snakeBody)
	{
		target.draw(piece); //Drawing the body blocks
	}
	target.draw(this->scoreText); //Drawing the player score text
	target.draw(this->finalScoreText); //Drawing the final score text
	target.draw(this->pausedText); //Drawing the paused text
}



//Function used for adding new blocks to the snake
void Player::growSnake()
{
	snakeBodyPiece newPiece; //New body piece
	newPiece.setPosition(snakeTail->getPosition()); //Setting the block position

	snakeTail = snakeBody.insert(snakeTail++, newPiece); //Inserting the new block into the body list
}

void Player::gameOver(sf::RenderTarget& target)
{
	this->isDead = true;
	this->isPaused = false;
	this->scoreText.setString("Game Over! Press 'R' to Retart the Game Or Press 'Esc' to Exit");
	this->scoreText.setPosition(375.f / 2, 0.f);
	this->scoreText.setCharacterSize(40);
	this->finalScoreText.setPosition(1750.f/2, 50);
	this->snakeDirection = {0.f,0.f}; //Stopping the snake
	this->score = 0; //Zeroing out the score
}

void Player::restartPlayer()
{
	this->snakeBody = (std::list<snakeBodyPiece>(4)); //Generating new body list
	this->snakeDirection = { 65.f,0.f }; //Adding new direction to the right
	snakeHead = --snakeBody.end(); //Setting head and tail position
	snakeTail = snakeBody.begin();
	this->initVariavles();
}

//Returns player bounds for collisions, etc.
const sf::FloatRect Player::getPlayerBounds() const
{
	return this->snakeHead->getGlobalBounds(); //Getting head bounds
}

//Initializing player variables
void Player::initVariavles()
{
	//Time and score
	elapsedTime = sf::Time::Zero; //Setting time elapsed as zero
	this->score = 0; //Setting the score as zero 

	//is player dead
	this->isDead = false;

	//Is game paused
	this->isPaused = false;

	//Initializing Text
	font.loadFromFile("DePixelBreit.ttf");
	scoreText.setPosition(1750.f/2, 0.f);
	scoreText.setFont(font);
	scoreText.setCharacterSize(30);

	//Initializing gameover score text
	finalScoreText.setPosition(100000.f, 1000000.f);
	finalScoreText.setFont(font);
	finalScoreText.setCharacterSize(40);

	//Paused text in center
	pausedText.setPosition(10000.f , 100000.f);
	pausedText.setFont(font);
	pausedText.setCharacterSize(40);
	pausedText.setFillColor(sf::Color::Red);
	

	//Initializing snake body
	float x = 65.f;
	for (auto& piece : this->snakeBody)
	{
		piece.setSize({ 60, 60 }); //Setting the size of the snake body piece
		piece.setFillColor(sf::Color::Green); //Setting the color of the snake body piece
		piece.setPosition({ x,65.f }); //Setting the position of the snake body piece
		x += 65; //Incrementing x position
	}
}

//Adding points to the player score
void Player::addScore(int points)
{
	this->score += points;
	std::cout << "Current score: " << this->score <<"\n";
}

//Constructor
Player::Player() : snakeBody(std::list<snakeBodyPiece>(4)), snakeDirection({ 65.f,0.f })
{
	this->snakeHead = --snakeBody.end();
	this->snakeTail = snakeBody.begin();
	this->initVariavles();
}

//Destructor
Player::~Player()
{
	std::cout << "Player removed\n";
}