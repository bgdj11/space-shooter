#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	std::shared_ptr<BasicEnemy> enemy1 = std::make_shared<BasicEnemy>(nullptr, sf::Vector2f(130.0f, 130.0f), sf::Vector2f(800.0f, 200.0f));
	firstWave.push_back(enemy1);
	std::shared_ptr<BasicEnemy> enemy2 = std::make_shared<BasicEnemy>(nullptr, sf::Vector2f(130.0f, 130.0f), sf::Vector2f(200.0f, 200.0f));
	firstWave.push_back(enemy2);
	std::shared_ptr<FirstBoss> boss1 = std::make_shared<FirstBoss>(nullptr, sf::Vector2f(180.0f, 180.0f), sf::Vector2f(500.0f, 150.0f));
	firstWave.push_back(boss1);

}

EnemyManager::~EnemyManager()
{
}

std::vector<std::shared_ptr<Enemy>>& EnemyManager::GetFirstWave()
{
	return firstWave;
}

void EnemyManager::DrawEnemies(sf::RenderWindow& window)
{
	for (auto& enemy : firstWave) 
	{
		enemy->Draw(window);
	}
}

void EnemyManager::Update()
{
	firstWave.erase(
		std::remove_if(firstWave.begin(), firstWave.end(),
			[](const std::shared_ptr<Enemy>& enemy) {return !enemy->GetStatus(); })
		, firstWave.end());
}
