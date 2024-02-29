#include "Background.h"

void CreateBackground(sf::View& view, sf::VertexArray& spaceBackground)
{
	spaceBackground[0].position = sf::Vector2f(0, 0);
	spaceBackground[1].position = sf::Vector2f(view.getSize().x / 2, 0);
	spaceBackground[2].position = sf::Vector2f(view.getSize().x / 2, view.getSize().y);
	spaceBackground[3].position = sf::Vector2f(0, view.getSize().y);

	spaceBackground[0].color = sf::Color(3, 2, 20);
	spaceBackground[1].color = sf::Color(10, 10, 35);
	spaceBackground[2].color = sf::Color(10, 10, 35);
	spaceBackground[3].color = sf::Color(3, 2, 20);


	spaceBackground[4].position = sf::Vector2f(view.getSize().x / 2, 0);
	spaceBackground[5].position = sf::Vector2f(view.getSize().x, 0);
	spaceBackground[6].position = sf::Vector2f(view.getSize().x, view.getSize().y);
	spaceBackground[7].position = sf::Vector2f(view.getSize().x / 2, view.getSize().y);

	spaceBackground[4].color = sf::Color(10, 10, 35);
	spaceBackground[5].color = sf::Color(3, 2, 20);
	spaceBackground[6].color = sf::Color(3, 2, 20);
	spaceBackground[7].color = sf::Color(10, 10, 35);
}

Background::Background(sf::View& view) 
	: spaceBackground(sf::Quads, 8), gen(std::random_device()()), disty(-200.0f, (float)view.getSize().y), distx(-10.0f, (float)view.getSize().x + 10.0f),
		dists(1.5f, 3.5f), distr(0.0f, 90.0f), distc(0, 255)
{
	CreateBackground(view, spaceBackground);

	for (int i = 0; i < 200; i++)
	{
		Star star;
		star.position = sf::Vector2f(distx(gen), disty(gen));
		star.size = dists(gen);
		star.rotation = distr(gen);
		star.velocity = sf::Vector2f(0.0f, 10.0f * star.size);
		star.color = sf::Color(255, 255, distc(gen));

		stars.push_back(star);
	}
}

Background::~Background()
{
}

void Background::Update(float deltaTime, float screenSize)
{
	for (auto& star : stars)
	{
		star.position += deltaTime * star.velocity;

		if (star.position.y >= screenSize + 10.0f)
			star.position.y = -100.0f;
	}
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(spaceBackground);

	for (auto& star : stars)
	{
		sf::RectangleShape square(sf::Vector2f(star.size, star.size));
		square.setPosition(star.position);
		square.setFillColor(star.color);
		square.setRotation(star.rotation);
		square.setOutlineColor(sf::Color::Black);
		square.setOutlineThickness(0.8f);
		window.draw(square);
	}
}
