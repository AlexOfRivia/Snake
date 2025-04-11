#pragma once
#include <iostream>
#include <list>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "snakeBodyPiece.h"

class Player
{
public:
	//Public functions
	void playerMovement(sf::Vector2f& moveDirection);
	void updatePlayer(sf::Time dt, sf::RenderWindow* win);
	void renderPlayer(sf::RenderTarget& target);
	void updateMovement();
	void growSnake();
	void gameOver(sf::RenderTarget& target);
	void restartPlayer();
	void addScore(int points);

	//Getting player bounds
	const sf::FloatRect getPlayerBounds() const;

	//Checking wether the head collides with the body
	bool isCollidingWithBody() const;


	//Public parameters
	bool isDead;

	//Constructor & Destructor
	Player();
	~Player();

private:
	//Private functions
	void initVariavles();

	bool isPaused;
	
	//Text
	sf::Text scoreText;
	sf::Text finalScoreText;
	sf::Text pausedText;
	sf::Font font;

	//Private parameters
	int score;
	sf::Time elapsedTime;
	sf::Vector2f snakeDirection;
	
	//Snake body
	std::list<snakeBodyPiece> snakeBody;
	std::list<snakeBodyPiece>::iterator snakeHead;
	std::list<snakeBodyPiece>::iterator snakeTail;
};

