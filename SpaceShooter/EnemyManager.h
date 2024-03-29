#pragma once
#include "Enemy.h"
#include "BasicEnemy.h"
#include "FirstBoss.h"
#include <memory>
#include "BigParticleSystem.h"
#include "SpriteManager.h"
#include "Rock.h"
#include <random>

class EnemyManager
{
private:
	std::vector<std::shared_ptr<Enemy>> firstWave;
	std::vector<std::shared_ptr<Enemy>> introWave;
	std::vector<std::shared_ptr<BigParticleSystem>> explosions;
	std::vector<std::shared_ptr<Enemy>> rocks;
	unsigned int activeWave;

	std::mt19937 gen;
	std::uniform_real_distribution<float> dist; 

public:
	EnemyManager(SpriteManager* spriteManager, sf::View& view);
	~EnemyManager();

	std::vector<std::shared_ptr<Enemy>>& GetIntroWave();
	std::vector<std::shared_ptr<Enemy>>& GetFirstWave();
	std::vector<std::shared_ptr<Enemy>>& GetSecondWawe();
	void DrawEnemies(sf::RenderWindow& window);
	void Update(float deltaTime, sf::RenderWindow& window);
	void AddExplosion(std::shared_ptr<BigParticleSystem> particleSystem);
	void CreateRocks(SpriteManager* spriteManager, float viewSizeX);
	void CreateFirstWave(SpriteManager* spriteManager, sf::View& view);
	void CreateIntroWave(SpriteManager* spriteManager, sf::View& view);
	unsigned int GetActiveWave();

};

