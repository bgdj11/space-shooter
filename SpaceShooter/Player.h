#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerProjectile.h"
#include "Animator.h"
#include "GameObject.h"
#include <memory>

class Player : public GameObject
{
public:
	Player(sf::Texture* texture, sf::Texture* projectileTexture, float speed, sf::View& view, sf::Vector2u imageCount, float switchTime);
	~Player();

	void Update(float deltaTime, sf::View& view);
	void Draw(sf::RenderWindow& window) override;
	void HandleInput(float deltaTime, sf::Vector2f* movement, float* fireTimer, int* bulletCnt);
	std::vector<std::shared_ptr<PlayerProjectile>>& GetPlayerProjectiles();

private:
	float speed;
	float rotation;
	std::vector<std::shared_ptr<PlayerProjectile>> projectiles;
	sf::Texture* projectileTexture;
	float fireRate;
	float fireTimer;
	float fireCooldown;
	int bulletCnt;
	Animator animator;
};


