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
	void addScore(int points);

	//Getting player bounds
	const sf::FloatRect getPlayerBounds() const;
	//Getting body bounds
	const sf::FloatRect getBodyBounds() const;
	bool isCollidingWithBody() const;


	//Public parameters
	bool isDead;

	//Constructor & Destructor
	Player(sf::RenderWindow* win);
	~Player();

private:
	//Private functions
	void initVariavles();

	//Private parameters
	float movementSpeed;
	int score;

	sf::Time elapsedTime;
	sf::Vector2f snakeDirection;
	std::list<sf::RectangleShape> snakeBody;
	std::list<sf::RectangleShape>::iterator snakeHead;
	std::list<sf::RectangleShape>::iterator snakeTail;
};

