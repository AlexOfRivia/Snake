#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

/*TODO
- MAKE THE SNAKE BODY A SEPPARATE OBJECT AND PUT IT INTO A VECTOR
*/

class Player
{
public:
	//Public functions
	void playerMovement(const float& dirX, const float& dirY);
	void updatePlayer(float dt, sf::RenderWindow* win);
	void addScore(int points);
	void renderPlayer(sf::RenderTarget& target);

	//Getting player bounds
	const sf::FloatRect getPlayerBounds() const;

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

	sf::RectangleShape playerShape;
};

