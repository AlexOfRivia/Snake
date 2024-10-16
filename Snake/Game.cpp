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
	this->player->updatePlayer(this->deltaTime, this->window);
	this->updateFood();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) && this->player->isDead==true)
	{
		std::cout << "Game Restarted\n";
		this->foodObj->moveFood(rand() % 1860, rand() % 1020);
		this->player->restartPlayer();
	}

}

//Updating player-food collision
void Game::updateFood()
{
	if (this->player->getPlayerBounds().intersects(this->foodObj->getFoodBounds()) )
	{
		this->player->growSnake();
		this->player->addScore(1);
		this->foodObj->moveFood(rand()%1860, rand()%1020);
		std::cout << "Collision detected\n";
	}
	if (this->player->isCollidingWithBody() == true)
	{
		this->foodObj->moveFood(10000.f, 10000.f);
		this->player->gameOver(*this->window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			this->window->close();
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
	this->player->renderPlayer(*this->window);
	this->foodObj->renderFood(*this->window);
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
	this->player = new Player();
	this->isPlayerDead == false;
	this->foodObj = new Food(this->window, rand() % 1920, rand() % 1080);
}

//Destructor
Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->foodObj;
	
}
