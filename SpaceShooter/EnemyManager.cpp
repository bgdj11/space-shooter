#include "EnemyManager.h"

EnemyManager::EnemyManager(SpriteManager* spriteManager)
{
	std::shared_ptr<BasicEnemy> enemy1 = std::make_shared<BasicEnemy>(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(800.0f, 200.0f));
	firstWave.push_back(enemy1);
	std::shared_ptr<BasicEnemy> enemy2 = std::make_shared<BasicEnemy>(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(200.0f, 200.0f));
	firstWave.push_back(enemy2);
	std::shared_ptr<FirstBoss> boss1 = std::make_shared<FirstBoss>(nullptr, sf::Vector2f(180.0f, 180.0f), sf::Vector2f(500.0f, 150.0f));
	firstWave.push_back(boss1);

	CreateRocks(spriteManager);
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
	if (!firstWave.empty())
	{
		for (auto& enemy : firstWave)
		{
			enemy->Draw(window);
		}
	}
	else
	{
		for (auto& enemy : rocks)
		{
			enemy->Draw(window);
		}
	}

	for (auto& partSys : explosions)
	{
		partSys->Draw(window, sf::RenderStates());
	}
}

void EnemyManager::Update(float deltaTime, sf::RenderWindow& window)
{
	if (!firstWave.empty()) 
	{
		firstWave.erase(
			std::remove_if(firstWave.begin(), firstWave.end(),
				[](const std::shared_ptr<Enemy>& enemy) {return !enemy->GetStatus(); })
			, firstWave.end());

		for (auto& enemy : firstWave)
		{
			enemy->Update(deltaTime);
		}
	}
	else
	{
		for (auto& enemy : rocks)
		{
			enemy->Update(deltaTime);

			if (enemy->GetPosition().y - 100.0f > window.getSize().y)
				enemy->SetStatus(false);
		}
		
		rocks.erase(
			std::remove_if(rocks.begin(), rocks.end(),
				[](const std::shared_ptr<Enemy>& enemy) {return !enemy->GetStatus(); })
			, rocks.end());
	}

	
	// PARTICLE EXPLOSION
	for (auto& partSys : explosions)
	{
		partSys->Update(deltaTime);
	}

	explosions.erase(
		std::remove_if(explosions.begin(), explosions.end(),
			[](const std::shared_ptr<BigParticleSystem>& bigParticle) {return !bigParticle->GetStatus(); })
		, explosions.end());
}

void EnemyManager::AddExplosion(std::shared_ptr<BigParticleSystem> particleSystem)
{
	explosions.push_back(particleSystem);
}

void EnemyManager::CreateRocks(SpriteManager* spriteManager)
{
	sf::Texture& rock1Texture = spriteManager->GetTexture("../sprites/rock1.png");
	sf::Texture& rock2Texture = spriteManager->GetTexture("../sprites/rock2.png");
	sf::Texture& rock3Texture = spriteManager->GetTexture("../sprites/rock3.png");
	sf::Texture& rock4Texture = spriteManager->GetTexture("../sprites/rock4.png");
	sf::Texture& rock5Texture = spriteManager->GetTexture("../sprites/rock5.png");

	std::shared_ptr<Rock> rock1_1 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0));
	std::shared_ptr<Rock> rock1_2 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0));
	std::shared_ptr<Rock> rock1_3 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0));
	std::shared_ptr<Rock> rock1_4 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0));
	std::shared_ptr<Rock> rock1_5 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0));
	std::shared_ptr<Rock> rock1_6 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0));
	std::shared_ptr<Rock> rock1_7 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0));
	std::shared_ptr<Rock> rock1_8 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0));
	std::shared_ptr<Rock> rock1_9 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0));
	rocks.push_back(rock1_1);
	rocks.push_back(rock1_2);
	rocks.push_back(rock1_3);
	rocks.push_back(rock1_4);
	rocks.push_back(rock1_5);
	rocks.push_back(rock1_6);
	rocks.push_back(rock1_7);
	rocks.push_back(rock1_8);
	rocks.push_back(rock1_9);
	std::shared_ptr<Rock> rock2_1 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0));
	std::shared_ptr<Rock> rock2_2 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0));
	std::shared_ptr<Rock> rock2_3 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0));
	std::shared_ptr<Rock> rock2_4 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0));
	std::shared_ptr<Rock> rock2_5 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0));
	std::shared_ptr<Rock> rock2_6 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0));
	std::shared_ptr<Rock> rock2_7 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0));
	std::shared_ptr<Rock> rock2_8 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0));
	std::shared_ptr<Rock> rock2_9 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0));
	rocks.push_back(rock2_1);
	rocks.push_back(rock2_2);
	rocks.push_back(rock2_3);
	rocks.push_back(rock2_4);
	rocks.push_back(rock2_5);
	rocks.push_back(rock2_6);
	rocks.push_back(rock2_7);
	rocks.push_back(rock2_8);
	rocks.push_back(rock2_9);
	std::shared_ptr<Rock> rock3_1 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0));
	std::shared_ptr<Rock> rock3_2 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0));
	std::shared_ptr<Rock> rock3_3 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0));
	std::shared_ptr<Rock> rock3_4 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0));
	std::shared_ptr<Rock> rock3_5 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0));
	std::shared_ptr<Rock> rock3_6 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0));
	rocks.push_back(rock3_1);
	rocks.push_back(rock3_2);
	rocks.push_back(rock3_3);
	rocks.push_back(rock3_4);
	rocks.push_back(rock3_5);
	rocks.push_back(rock3_6);
	std::shared_ptr<Rock> rock4_1 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0));
	std::shared_ptr<Rock> rock4_2 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0));
	std::shared_ptr<Rock> rock4_3 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0));
	std::shared_ptr<Rock> rock4_4 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0));
	std::shared_ptr<Rock> rock4_5 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0));
	std::shared_ptr<Rock> rock4_6 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0));
	rocks.push_back(rock4_1);
	rocks.push_back(rock4_2);
	rocks.push_back(rock4_3);
	rocks.push_back(rock4_4);
	rocks.push_back(rock4_5);
	rocks.push_back(rock4_6);
	std::shared_ptr<Rock> rock5_1 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0));
	std::shared_ptr<Rock> rock5_2 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0));
	std::shared_ptr<Rock> rock5_3 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0));
	std::shared_ptr<Rock> rock5_4 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0));
	std::shared_ptr<Rock> rock5_5 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0));
	std::shared_ptr<Rock> rock5_6 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0));
	rocks.push_back(rock5_1);
	rocks.push_back(rock5_2);
	rocks.push_back(rock5_3);
	rocks.push_back(rock5_4);
	rocks.push_back(rock5_5);
	rocks.push_back(rock5_6);
}
