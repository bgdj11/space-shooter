#pragma once
#include "GameObject.h"
#include "EnemyProjectile.h"
#include "BigParticleSystem.h"

class Enemy : public GameObject
{
protected:
    int health;
	int damage;
	bool status;
	float speed;
	sf::Vector2f basePosition;
	std::vector<std::shared_ptr<EnemyProjectile>> projectiles;
	std::vector<std::shared_ptr<BigParticleSystem>> explosions;
	float hurtTimer;
	int appearance;
	
public:
	void TakeDamage(int damage);
	int GetDamage();
	int GetHealth();
	void SetStatus(bool status);
	bool GetStatus();
	virtual void Update(float deltaTime);
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f position);
	std::vector<std::shared_ptr<EnemyProjectile>>& GetProjectiles();
	void AddExplosion(std::shared_ptr<BigParticleSystem> particleSystem);
	void Hurt();
	void UpdateAppearance();
	int GetAppearance();
};

