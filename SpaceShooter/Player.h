#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerProjectile.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Texture* projectileTexture ,float speed);
	~Player();

	void Update(float deltaTime, sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void HandleInput(float deltaTime, sf::Vector2f* movement, float* fireTimer);

private:
	sf::RectangleShape body;
	float speed;
	float rotation;
	std::vector<PlayerProjectile> projectiles;
	sf::Texture* projectileTexture;
	float fireRate;
	float fireTimer;
};


