#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000.0f, 1000.0f), "Space Shooter", sf::Style::Close | sf::Style::Resize);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("../sprites/spaceship.png");
	sf::Texture playerProjectileTexture;
	playerProjectileTexture.loadFromFile("../sprites/bullet.png");

	Player player(&playerTexture, &playerProjectileTexture, 600.f);

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
		}

		player.Update(deltaTime,window);
		window.clear(sf::Color(245, 66, 93));
		player.Draw(window);
		window.display();
	}
    return 0;
}