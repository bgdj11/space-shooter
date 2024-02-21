#pragma once
#include "Enemy.h"
#include "BasicEnemy.h"
#include "FirstBoss.h"
#include <memory>

class EnemyManager
{
private:
	std::vector<std::shared_ptr<Enemy>> firstWave;

public:
	EnemyManager();
	~EnemyManager();

	std::vector<std::shared_ptr<Enemy>>& GetFirstWave();
	void DrawEnemies(sf::RenderWindow& window);

	void Update();

};

