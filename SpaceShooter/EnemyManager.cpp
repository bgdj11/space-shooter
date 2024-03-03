#include "EnemyManager.h"

EnemyManager::EnemyManager(SpriteManager* spriteManager, sf::View& view)
	: gen(std::random_device()()), dist(-8000.0f, -100.0f)
{
	CreateFirstWave(spriteManager, view);
	CreateRocks(spriteManager, view.getSize().x);

	activeWave = 1;
}

EnemyManager::~EnemyManager()
{
}

std::vector<std::shared_ptr<Enemy>>& EnemyManager::GetFirstWave()
{
	return firstWave;
}

std::vector<std::shared_ptr<Enemy>>& EnemyManager::GetSecondWawe()
{
	return rocks;
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
		activeWave = 2;

		for (auto& enemy : rocks)
		{
			enemy->Update(deltaTime);

			if (enemy->GetPosition().y - 400.0f > window.getSize().y)
			{
				enemy->UpdateAppearance();
				if (enemy->GetAppearance() == 3)
					enemy->SetStatus(false);	
				else 
					enemy->SetPosition(sf::Vector2f(enemy->GetPosition().x, dist(gen)));
					
					
			}
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

void EnemyManager::CreateRocks(SpriteManager* spriteManager, float viewSizeX)
{
	sf::Texture& rock1Texture = spriteManager->GetTexture("../sprites/rock1.png");
	sf::Texture& rock2Texture = spriteManager->GetTexture("../sprites/rock2.png");
	sf::Texture& rock3Texture = spriteManager->GetTexture("../sprites/rock3.png");
	sf::Texture& rock4Texture = spriteManager->GetTexture("../sprites/rock4.png");
	sf::Texture& rock5Texture = spriteManager->GetTexture("../sprites/rock5.png");

	std::shared_ptr<Rock> rock1_1 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_2 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_3 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_4 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_5 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_6 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_7 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_8 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_9 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_10 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_11 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_12 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_13 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_14 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	std::shared_ptr<Rock> rock1_15 = std::make_shared<Rock>(&rock1Texture, sf::Vector2f(72.0, 66.0), viewSizeX);
	rocks.push_back(rock1_1);
	rocks.push_back(rock1_2);
	rocks.push_back(rock1_3);
	rocks.push_back(rock1_4);
	rocks.push_back(rock1_5);
	rocks.push_back(rock1_6);
	rocks.push_back(rock1_7);
	rocks.push_back(rock1_8);
	rocks.push_back(rock1_9);
	rocks.push_back(rock1_10);
	rocks.push_back(rock1_11);
	rocks.push_back(rock1_12);
	rocks.push_back(rock1_13);
	rocks.push_back(rock1_14);
	rocks.push_back(rock1_15);
	std::shared_ptr<Rock> rock2_1 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_2 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_3 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_4 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_5 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_6 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_7 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_8 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_9 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_10 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_11 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_12 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_13 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_14 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	std::shared_ptr<Rock> rock2_15 = std::make_shared<Rock>(&rock2Texture, sf::Vector2f(66.0, 72.0), viewSizeX);
	rocks.push_back(rock2_1);
	rocks.push_back(rock2_2);
	rocks.push_back(rock2_3);
	rocks.push_back(rock2_4);
	rocks.push_back(rock2_5);
	rocks.push_back(rock2_6);
	rocks.push_back(rock2_7);
	rocks.push_back(rock2_8);
	rocks.push_back(rock2_9);
	rocks.push_back(rock2_10);
	rocks.push_back(rock2_11);
	rocks.push_back(rock2_12);
	rocks.push_back(rock2_13);
	rocks.push_back(rock2_14);
	rocks.push_back(rock2_15);
	std::shared_ptr<Rock> rock3_1 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0), viewSizeX);
	std::shared_ptr<Rock> rock3_2 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0), viewSizeX);
	std::shared_ptr<Rock> rock3_3 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0), viewSizeX);
	std::shared_ptr<Rock> rock3_4 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0), viewSizeX);
	std::shared_ptr<Rock> rock3_5 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0), viewSizeX);
	std::shared_ptr<Rock> rock3_6 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0), viewSizeX);
	std::shared_ptr<Rock> rock3_7 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0), viewSizeX);
	std::shared_ptr<Rock> rock3_8 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0), viewSizeX);
	std::shared_ptr<Rock> rock3_9 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0), viewSizeX);
	std::shared_ptr<Rock> rock3_10 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0), viewSizeX);
	std::shared_ptr<Rock> rock3_11 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0), viewSizeX);
	std::shared_ptr<Rock> rock3_12 = std::make_shared<Rock>(&rock3Texture, sf::Vector2f(115.0, 111.0), viewSizeX);
	rocks.push_back(rock3_1);
	rocks.push_back(rock3_2);
	rocks.push_back(rock3_3);
	rocks.push_back(rock3_4);
	rocks.push_back(rock3_5);
	rocks.push_back(rock3_6);
	rocks.push_back(rock3_7);
	rocks.push_back(rock3_8);
	rocks.push_back(rock3_9);
	rocks.push_back(rock3_10);
	rocks.push_back(rock3_11);
	rocks.push_back(rock3_12);
	std::shared_ptr<Rock> rock4_1 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0), viewSizeX);
	std::shared_ptr<Rock> rock4_2 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0), viewSizeX);
	std::shared_ptr<Rock> rock4_3 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0), viewSizeX);
	std::shared_ptr<Rock> rock4_4 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0), viewSizeX);
	std::shared_ptr<Rock> rock4_5 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0), viewSizeX);
	std::shared_ptr<Rock> rock4_6 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0), viewSizeX);
	std::shared_ptr<Rock> rock4_7 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0), viewSizeX);
	std::shared_ptr<Rock> rock4_8 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0), viewSizeX);
	std::shared_ptr<Rock> rock4_9 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0), viewSizeX);
	std::shared_ptr<Rock> rock4_10 = std::make_shared<Rock>(&rock4Texture, sf::Vector2f(152.0, 146.0), viewSizeX);
	rocks.push_back(rock4_1);
	rocks.push_back(rock4_2);
	rocks.push_back(rock4_3);
	rocks.push_back(rock4_4);
	rocks.push_back(rock4_5);
	rocks.push_back(rock4_6);
	rocks.push_back(rock4_7);
	rocks.push_back(rock4_8);
	rocks.push_back(rock4_9);
	rocks.push_back(rock4_10);
	std::shared_ptr<Rock> rock5_1 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0), viewSizeX);
	std::shared_ptr<Rock> rock5_2 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0), viewSizeX);
	std::shared_ptr<Rock> rock5_3 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0), viewSizeX);
	std::shared_ptr<Rock> rock5_4 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0), viewSizeX);
	std::shared_ptr<Rock> rock5_5 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0), viewSizeX);
	std::shared_ptr<Rock> rock5_6 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0), viewSizeX);
	std::shared_ptr<Rock> rock5_7 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0), viewSizeX);
	std::shared_ptr<Rock> rock5_8 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0), viewSizeX);
	std::shared_ptr<Rock> rock5_9 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0), viewSizeX);
	std::shared_ptr<Rock> rock5_10 = std::make_shared<Rock>(&rock5Texture, sf::Vector2f(173.0, 132.0), viewSizeX);
	rocks.push_back(rock5_1);
	rocks.push_back(rock5_2);
	rocks.push_back(rock5_3);
	rocks.push_back(rock5_4);
	rocks.push_back(rock5_5);
	rocks.push_back(rock5_6);
	rocks.push_back(rock5_7);
	rocks.push_back(rock5_8);
	rocks.push_back(rock5_9);
	rocks.push_back(rock5_10);
}

void EnemyManager::CreateFirstWave(SpriteManager* spriteManager, sf::View& view)
{
	sf::Texture& firstBossTexture = spriteManager->GetTexture("../sprites/Boss_1_Ss_png.png");
	sf::Texture& firstEnemyTexture = spriteManager->GetTexture("../sprites/Enemy1_Ss_png.png");
	sf::Texture& basicEnemyProjectileTexture = spriteManager->GetTexture("../sprites/enemy_laser.png");
	sf::Texture& firstBossProjectileTexture = spriteManager->GetTexture("../sprites/Enemy_A1_Ss_Png.png");

	std::shared_ptr<BasicEnemy> enemy1 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x * 0.2f, 160.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy1);
	std::shared_ptr<BasicEnemy> enemy2 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x * 0.8f, 160.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy2);
	std::shared_ptr<BasicEnemy> enemy3 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x * 0.3f, 250.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy3);
	std::shared_ptr<BasicEnemy> enemy4 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x * 0.7f, 250.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy4);
	std::shared_ptr<BasicEnemy> enemy5 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x * 0.45f, 460.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy5);
	std::shared_ptr<BasicEnemy> enemy6 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x * 0.55f, 460.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy6);
	std::shared_ptr<BasicEnemy> enemy7 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x * 0.85f, 350.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy7);
	std::shared_ptr<BasicEnemy> enemy8 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x * 0.15f, 350.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy8);
	std::shared_ptr<BasicEnemy> enemy9 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x / 2.0f, 290.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy9);
	std::shared_ptr<BasicEnemy> enemy10 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x * 0.4f, 290.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy10);
	std::shared_ptr<BasicEnemy> enemy11 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x * 0.6f, 290.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy11);
	std::shared_ptr<BasicEnemy> enemy12 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x * 0.12f, 220.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy12);
	std::shared_ptr<BasicEnemy> enemy13 = std::make_shared<BasicEnemy>(&firstEnemyTexture, sf::Vector2f(290.0f, 86.0f), sf::Vector2f(view.getSize().x * 0.88f, 220.0f), &basicEnemyProjectileTexture);
	firstWave.push_back(enemy13);
	std::shared_ptr<FirstBoss> boss1 = std::make_shared<FirstBoss>(&firstBossTexture, sf::Vector2f(500.0f, 160.0f), sf::Vector2f(view.getSize().x / 2.0f, 150.0f), &firstBossProjectileTexture);
	firstWave.push_back(boss1);
}

unsigned int EnemyManager::GetActiveWave()
{
	return activeWave;
}
