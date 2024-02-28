#pragma once
#include "Enemy.h"
#include <cmath>
#include "Animator.h"
#include <random>
#include "EnemyProjectile.h"
#include "BigParticleSystem.h"

class BasicEnemy : public Enemy
{
public:
	BasicEnemy(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Texture* projectileTexture);
	~BasicEnemy();
	void Update(float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

private:
	bool movingLeft;
	float accumulatedTime;
	bool atPosition;
	float fireCooldown;
	float fireTimer;
	Animator animator;
	sf::Texture* projectileTexture;
};

