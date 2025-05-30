#include "Game.h"

//Updating events in the game
void Game::updateEvents()
{
	sf::Clock clock;
	deltaTime = sf::seconds(1.f/60.f); 

	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}

	//Player Movement
	this->player->updatePlayer(this->deltaTime, this->window); //Updating the player
	this->updateFood(); //Updating the food (changing it's position)

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) && this->player->isDead==true) //Checking for key press and isDead bool
	{
		std::cout << "Game Restarted\n";

		int xIndex = rand() % this->gridXAxis.size(); //Randomizing the food position
		int yIndex = rand() % this->gridYAxis.size(); //Randomizing the food position

		this->foodObj->moveFood(gridXAxis[xIndex], gridYAxis[yIndex]); //Moving the food object
		this->player->restartPlayer(); //Restarting the player
	}
}

//Updating player-food collision
void Game::updateFood()
{
	if (this->player->getPlayerBounds().intersects(this->foodObj->getFoodBounds()) ) //If player touches the food object
	{
		this->player->growSnake(); //Growing the snake
		this->player->addScore(1); //INcrementing the score

		int xIndex = rand() % this->gridXAxis.size(); //Randomizing the food position
		int yIndex = rand() % this->gridYAxis.size(); //Randomizing the food position

		this->foodObj->moveFood(gridXAxis[xIndex], gridYAxis[yIndex]); //Moving the food object
		std::cout << "Collision detected\n"; //Debugging information
	} 
	if (this->player->isCollidingWithBody() == true) //Checking if the snake is colliding with itself
	{
		this->foodObj->moveFood(10000.f, 10000.f); //Moving the food out of screen bounds
		this->player->gameOver(*this->window); //Displaying the game over screen
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) //Checking if escape key is pressed
		{
			this->window->close(); //Closing the window
		}
		this->isPlayerDead = true; 
	}
}

//Updating the game overall
void Game::Update()
{
	this->updateEvents();
}

//Rendering everything to the window
void Game::Render()
{
	this->window->clear(sf::Color(37, 37, 37, 0)); //Clears old frame
	//Rendering(drawing) the objects
	this->player->renderPlayer(*this->window); //Rednering the player
	this->foodObj->renderFood(*this->window); //Rendering the food
	this->window->display(); //Displays new frame
}

//Initializing game variables
void Game::InitVariables()
{
	this->window = nullptr;
}

//Initializing the window
void Game::InitWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Snake", sf::Style::Fullscreen);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

//Checking wether the window is running
const bool Game::isRunning() const
{
	return this->window->isOpen();
}

//Constructor
Game::Game()
{
	this->InitVariables(); //this function must be first, because of window being set to nullptr
	this->InitWindow();

	//Initializing gthe grid
	for (int i = 0; i < 31; i++)
	{
		this->gridXAxis.push_back(i * 60.f); //Creating a grid for the snake
	}
	for (int i = 0; i < 17; i++)
	{
		this->gridYAxis.push_back(i * 60.f); //Creating a grid for the snake
	}

	int xIndex = rand() % this->gridXAxis.size(); //Randomizing the food position
	int yIndex = rand() % this->gridYAxis.size(); //Randomizing the food position

	this->player = new Player(); //Creating new player object
	this->isPlayerDead =false;
	this->foodObj = new Food(this->window, gridXAxis[xIndex], gridYAxis[yIndex]); //Creating new food object
}

//Destructor 
Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->foodObj;
}
