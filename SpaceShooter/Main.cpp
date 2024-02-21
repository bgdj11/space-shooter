#include <SFML/Graphics.hpp>
#include "Player.h"
#include "EnemyManager.h"

static const float VIEW_WIDTH = 1000.0f;
static const float VIEW_HEIGHT = 1000.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	float gameAspectRatio = VIEW_WIDTH / VIEW_HEIGHT;

	if (aspectRatio > gameAspectRatio) 
	{
		// Window is wider then needed
		sf::Vector2f newSize(gameAspectRatio * window.getSize().y, window.getSize().y);
		view.setSize(newSize);
		view.setCenter(newSize.x / 2, newSize.y / 2);

		sf::Vector2f newPosition((window.getSize().x - newSize.x) / 2.0f, 0.0f);
		view.setViewport(sf::FloatRect(newPosition.x / window.getSize().x, newPosition.y / window.getSize().y,
			newSize.x / window.getSize().x, newSize.y / window.getSize().y));
	}
	else
	{
		// Window is narrower than needed
		sf::Vector2f newSize(window.getSize().x, window.getSize().x / gameAspectRatio);
		view.setSize(newSize);
		view.setCenter(newSize.x / 2, newSize.y / 2);

		sf::Vector2f newPosition(0.0f, (window.getSize().y - newSize.y) / 2.0f);
		view.setViewport(sf::FloatRect(newPosition.x / window.getSize().x, newPosition.y / window.getSize().y,
			newSize.x / window.getSize().x, newSize.y / window.getSize().y));
	}
}

void HandleCollisions(Player& player, EnemyManager& enemyManager)
{

	for (auto& playerProjectile: player.GetPlayerProjectiles())
	{
		for (auto& enemy : enemyManager.GetFirstWave())
		{
			if (enemy->GetCollider().CheckCollision(playerProjectile->GetCollider()))
			{
				playerProjectile->SetStatus(false);
				enemy->TakeDamage(playerProjectile->GetDamage());
				if (enemy->GetHealth() <= 0) {
					enemy->SetStatus(false);
				}
			}
		}
	}

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000.0f, 1000.0f), "Space Shooter", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::FloatRect(0, 0, VIEW_WIDTH, VIEW_HEIGHT));

    sf::Texture playerTexture;
    playerTexture.loadFromFile("../sprites/Engine_Ss_png.png");
	sf::Texture playerProjectileTexture;
	playerProjectileTexture.loadFromFile("../sprites/bullet_removed.png");
	sf::Texture enemyTexture;
	enemyTexture.loadFromFile("../sprites/ship_removed.png");

	Player player(&playerTexture, &playerProjectileTexture, 600.f, view, sf::Vector2u(4, 1), 0.1f);
	EnemyManager enemyManager;

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

		sf::RectangleShape background(sf::Vector2f(view.getSize().x, view.getSize().y));
		background.setFillColor(sf::Color(245, 66, 93));
		window.draw(background);

		player.Update(deltaTime,view);
		HandleCollisions(player, enemyManager);
		enemyManager.Update();
		player.Draw(window);
		enemyManager.DrawEnemies(window);
		window.display();
	}
    return 0;
}