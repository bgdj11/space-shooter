#pragma once
#include "Enemy.h"
#include "BasicEnemy.h"
#include "FirstBoss.h"
#include <memory>
#include "BigParticleSystem.h"
#include "SpriteManager.h"
#include "Rock.h"

class EnemyManager
{
private:
	std::vector<std::shared_ptr<Enemy>> firstWave;
	std::vector<std::shared_ptr<BigParticleSystem>> explosions;
	std::vector<std::shared_ptr<Enemy>> rocks;
	unsigned int activeWave;

public:
	EnemyManager(SpriteManager* spriteManager, sf::View& view);
	~EnemyManager();

	std::vector<std::shared_ptr<Enemy>>& GetFirstWave();
	std::vector<std::shared_ptr<Enemy>>& GetSecondWawe();
	void DrawEnemies(sf::RenderWindow& window);
	void Update(float deltaTime, sf::RenderWindow& window);
	void AddExplosion(std::shared_ptr<BigParticleSystem> particleSystem);
	void CreateRocks(SpriteManager* spriteManager, float viewSizeX);
	void CreateFirstWave(SpriteManager* spriteManager, sf::View& view);
	unsigned int GetActiveWave();

};

