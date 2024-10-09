#pragma once
#include <iostream>
#include <list>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


class Player
{
public:
	//Public functions
	void playerMovement(sf::Vector2f& moveDirection);
	void updatePlayer(sf::Time dt, sf::RenderWindow* win);
	void renderPlayer(sf::RenderTarget& target);
	void updateMovement();
	void growSnake();
	void gameOver();
	void addScore(int points);

	//Getting player bounds
	const sf::FloatRect getPlayerBounds() const;

	//Checking wether the head collides with the body
	bool isCollidingWithBody() const;


	//Public parameters
	bool isDead;

	//Constructor & Destructor
	Player(sf::RenderWindow* win);
	~Player();

private:
	//Private functions
	void initVariavles();
	
	//Text
	sf::Text scoreText;
	sf::Font font;

	//Private parameters
	int score;
	sf::Time elapsedTime;
	sf::Vector2f snakeDirection;
	
	//Snake body
	std::list<sf::RectangleShape> snakeBody;
	std::list<sf::RectangleShape>::iterator snakeHead;
	std::list<sf::RectangleShape>::iterator snakeTail;
};

