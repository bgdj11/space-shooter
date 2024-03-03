#include <SFML/Graphics.hpp>
#include "Player.h"
#include "EnemyManager.h"
#include "BigParticleSystem.h"
#include <memory>
#include "SpriteManager.h"
#include <iostream>
#include "Background.h"

static const float VIEW_WIDTH = 1080.0f;
static const float VIEW_HEIGHT = 1080.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	float gameAspectRatio = VIEW_WIDTH / VIEW_HEIGHT;

	if (aspectRatio > gameAspectRatio) 
	{
		// Window is wider then needed
		sf::Vector2f newSize(gameAspectRatio * (float)window.getSize().y, (float)window.getSize().y);
		view.setSize(newSize);
		view.setCenter(newSize.x / 2, newSize.y / 2);

		sf::Vector2f newPosition(((float)window.getSize().x - newSize.x) / 2.0f, 0.0f);
		view.setViewport(sf::FloatRect(newPosition.x / (float)window.getSize().x, newPosition.y / (float)window.getSize().y,
			newSize.x / (float)window.getSize().x, newSize.y / (float)window.getSize().y));
	}
	else
	{
		// Window is narrower than needed
		sf::Vector2f newSize((float)window.getSize().x, (float)window.getSize().x / gameAspectRatio);
		view.setSize(newSize);
		view.setCenter(newSize.x / 2, newSize.y / 2);

		sf::Vector2f newPosition(0.0f, ((float)window.getSize().y - newSize.y) / 2.0f);
		view.setViewport(sf::FloatRect(newPosition.x / (float)window.getSize().x, newPosition.y / (float)window.getSize().y,
			newSize.x / (float)window.getSize().x, newSize.y / (float)window.getSize().y));
	}
}

void HandleCollisions(Player& player, EnemyManager& enemyManager)
{
	if (enemyManager.GetActiveWave() == 1)
	{
		for (auto& enemy : enemyManager.GetFirstWave())
		{
			for (auto& playerProjectile : player.GetPlayerProjectiles()) 
			{
				if (enemy->GetCollider().CheckCollision(playerProjectile->GetCollider()))
				{
					playerProjectile->SetStatus(false);
					enemy->TakeDamage(playerProjectile->GetDamage());
					if (enemy->GetHealth() <= 0) 
					{
						// enemy death
						enemy->SetStatus(false);
						if (!enemy->IsBoss())
						{
							std::shared_ptr<BigParticleSystem> explosion = std::make_shared<BigParticleSystem>(80, 2.0f, sf::Color(166, 68, 151), enemy->GetPosition(), 3.0f, 10.0f, 2.5f);
							enemyManager.AddExplosion(explosion);
						}
						else
						{
							// Boss explosion
							std::shared_ptr<BigParticleSystem> explosion1 = std::make_shared<BigParticleSystem>(200, 2.0f, sf::Color(166, 68, 151), enemy->GetPosition(), 3.2f, 13.0f, 3.5f);
							std::shared_ptr<BigParticleSystem> explosion2 = std::make_shared<BigParticleSystem>(40, 1.5f, sf::Color(207, 194, 17), enemy->GetPosition(), 3.0f, 5.0f, 2.0f);
							enemyManager.AddExplosion(explosion1);
							enemyManager.AddExplosion(explosion2);
						}
					}

					std::shared_ptr<BigParticleSystem> explosion = std::make_shared<BigParticleSystem>(12, 2.0f, sf::Color(252, 186, 3), playerProjectile->GetPosition(), 3.0f, 6.0f, 1.0f);
					player.AddExplosion(explosion);
				}
			}
				
			for (auto& enemyProjectile : enemy->GetProjectiles())
			{
				if (enemyProjectile->GetCollider().CheckCollision(player.GetCollider()))
				{
					enemyProjectile->SetStatus(false);
					player.TakeDamage(enemyProjectile->GetDamage());
					std::shared_ptr<BigParticleSystem> explosion = std::make_shared<BigParticleSystem>(20, 2.0f, sf::Color(252, 186, 3), enemyProjectile->GetPosition(), 3.0f, 6.0f, 1.0f);
					enemy->AddExplosion(explosion);
				}
			}

		}
	}

	if (enemyManager.GetActiveWave() == 2)
	{
		for (auto& enemy : enemyManager.GetSecondWawe())
		{
			if (enemy->GetCollider().CheckCollision(player.GetCollider()))
			{
				player.TakeDamage(enemy->GetDamage());
				enemy->SetStatus(false);
				std::shared_ptr<BigParticleSystem> explosion = std::make_shared<BigParticleSystem>(60, 2.0f, sf::Color(186, 163, 123), enemy->GetPosition(), 3.0f, 15.0f, 2.0f);
				enemyManager.AddExplosion(explosion);

				if (player.GetHealth() <= 0)
					std::cout << "GAME OVER !!!" << std::endl;
			}

			for (auto& playerProjectile : player.GetPlayerProjectiles())
			{
				if (enemy->GetCollider().CheckCollision(playerProjectile->GetCollider()))
				{
					playerProjectile->SetStatus(false);
					enemy->TakeDamage(playerProjectile->GetDamage());
					if (enemy->GetHealth() <= 0) {
						enemy->SetStatus(false);
						std::shared_ptr<BigParticleSystem> explosion = std::make_shared<BigParticleSystem>(60, 2.0f, sf::Color(179, 138, 73), enemy->GetPosition(), 3.0f, 15.0f, 2.0f);
						enemyManager.AddExplosion(explosion);
					}

					std::shared_ptr<BigParticleSystem> explosion = std::make_shared<BigParticleSystem>(12, 2.0f, sf::Color(240, 0, 0), playerProjectile->GetPosition(), 3.0f, 6.0f, 1.0f);
					player.AddExplosion(explosion);
				}
			}
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Shooter", sf::Style::Fullscreen);
	sf::View view(sf::FloatRect(0, 0, VIEW_WIDTH, VIEW_HEIGHT));

	ResizeView(window, view);

	SpriteManager spriteManager;

	sf::Texture&  playerTexture = spriteManager.GetTexture("../sprites/Engine_Ss_png.png");
	sf::Texture& playerProjectileTexture = spriteManager.GetTexture("../sprites/Projectile_png.png");
	sf::Texture enemyTexture;

	Player player(&playerTexture, &playerProjectileTexture, 600.f, view, sf::Vector2u(4, 1), 0.1f);
	EnemyManager enemyManager(&spriteManager, view);

	Background background(view);

    // TIME
    float deltaTime = 0.0f;
    sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				window.close();
			else if (ev.type == sf::Event::Resized)
				ResizeView(window, view);
		}

		window.clear(sf::Color::Black);
		window.setView(view);

		background.Update(deltaTime, view.getSize().y);
		background.Draw(window);

		player.Update(deltaTime,view);
		HandleCollisions(player, enemyManager);
		enemyManager.Update(deltaTime, window);
		player.Draw(window);
		enemyManager.DrawEnemies(window);

		background.DrawFrame(window);

		window.display();
	}
    return 0;
}