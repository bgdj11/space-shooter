#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerProjectile.h"
#include "Animator.h"
#include "GameObject.h"
#include <memory>
#include "BigParticleSystem.h"

class Player : public GameObject
{
public:
	Player(sf::Texture* texture, sf::Texture* projectileTexture, float speed, sf::View& view, sf::Vector2u imageCount, float switchTime);
	~Player();

	void Update(float deltaTime, sf::View& view);
	void Draw(sf::RenderWindow& window) override;
	void HandleInput(float deltaTime, sf::Vector2f* movement, float* fireTimer, int* bulletCnt);
	std::vector<std::shared_ptr<PlayerProjectile>>& GetPlayerProjectiles();
	void AddExplosion(std::shared_ptr<BigParticleSystem> particleSystem);
	void TakeDamage(int damage);
	int GetHealth();
	void Hurt();
	bool ShieldActive();

private:
	int health;
	float speed;
	float rotation;
	std::vector<std::shared_ptr<PlayerProjectile>> projectiles;
	sf::Texture* projectileTexture;
	float fireRate;
	float fireTimer;
	float fireCooldown;
	int bulletCnt;
	Animator animator;
	std::vector<std::shared_ptr<BigParticleSystem>> explosions;
	float hurtTimer;
	float shieldTimer;
	float shieldResetTimer;
	bool isShieldActive;
};


