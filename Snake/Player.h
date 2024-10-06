#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Player
{
public:
	//Public functions
	void playerMovement(const float& dirX, const float& dirY);
	void updatePlayer(float dt, sf::RenderWindow* win);
	void addScore(int points);
	void renderPlayer(sf::RenderTarget& target);

	const sf::FloatRect playerBounds() const; //Returns player bounds

	//Constructor & Destructor
	Player(sf::RenderWindow* win);
	~Player();

private:
	//Private functions
	void initVariavles();
	float movementSpeed;
	int score;

	sf::RectangleShape playerShape;
};

