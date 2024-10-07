#pragma once
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


class Player
{
public:
	//Public functions
	void playerMovement(const float& dirX, const float& dirY);
	void updatePlayer(sf::Time dt, sf::RenderWindow* win);
	void renderPlayer(sf::RenderTarget& target);
	void growSnake();
	void addScore(int points);

	//Getting player bounds
	const sf::FloatRect getPlayerBounds() const;
	//Getting body bounds
	const sf::FloatRect getBodyBounds() const;


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
	std::list<sf::RectangleShape> snakeBody;
	std::list<sf::RectangleShape>::iterator snakeHead;
	std::list<sf::RectangleShape>::iterator snakeTail;
};

