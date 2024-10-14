#include "MainMenu.h"

void MainMenu::Update()
{
	//poolEvent updates
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			this->window->close();
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		//Application(Game) Loop
		while (game.isRunning())
		{
			//Update
			game.Update();
			//Rendering
			game.Render();
		}

	}
}

void MainMenu::Render()
{
	this->window->clear(sf::Color(37, 37, 37, 0)); //Clears old frame
	
	//Text and buttons here

	this->window->display();
}

const bool MainMenu::isMenuRunning() const
{
	return this->window->isOpen();
}
