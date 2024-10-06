#include "Game.h"

//Updating events in the game
void Game::updateEvents()
{
	sf::Clock clock;
	float dt = clock.restart().asSeconds();

	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}

	//Player Movement
	this->player->updatePlayer(dt, this->window);

	if (this->player->getPlayerBounds().intersects(this->food->getFoodBounds()))
	{
		
		std::cout << "Collision\n";
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
	this->window->clear(sf::Color::Black); //Clears old frame
	//Rendering(drawing) the objects
	this->player->renderPlayer(*this->window);
	this->food->renderFood(*this->window);
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
	this->player = new Player(this->window);
	this->food = new Food(this->window);
}

//Destructor
Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->food;
}
