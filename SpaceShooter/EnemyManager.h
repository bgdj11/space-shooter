#pragma once
#include "Enemy.h"
#include "BasicEnemy.h"
#include "FirstBoss.h"
#include <memory>
#include "BigParticleSystem.h"

class EnemyManager
{
private:
	std::vector<std::shared_ptr<Enemy>> firstWave;
	std::vector<std::shared_ptr<BigParticleSystem>> explosions;

public:
	EnemyManager();
	~EnemyManager();

	std::vector<std::shared_ptr<Enemy>>& GetFirstWave();
	void DrawEnemies(sf::RenderWindow& window);
	void Update(float deltaTime);
	void AddExplosion(std::shared_ptr<BigParticleSystem> particleSystem);

};

