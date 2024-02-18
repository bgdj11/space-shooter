#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerProjectile.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Texture* projectileTexture ,float speed, sf::View& view);
	~Player();

	void Update(float deltaTime, sf::View& view);
	void Draw(sf::RenderWindow& window);
	void HandleInput(float deltaTime, sf::Vector2f* movement, float* fireTimer, int* bulletCnt);

private:
	sf::RectangleShape body;
	float speed;
	float rotation;
	std::vector<PlayerProjectile> projectiles;
	sf::Texture* projectileTexture;
	float fireRate;
	float fireTimer;
	float fireCooldown;
	int bulletCnt;
};


