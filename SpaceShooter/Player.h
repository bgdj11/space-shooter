#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerProjectile.h"
#include "Collider.h"
#include "EnemyContainer.h"
#include "Animator.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Texture* projectileTexture, float speed, sf::View& view, sf::Vector2u imageCount, float switchTime);
	~Player();

	void Update(float deltaTime, sf::View& view, EnemyContainer* enemy);
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
	Animator animator;
};


