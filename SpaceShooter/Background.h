#pragma once
#include <SFML/Graphics.hpp>
#include <random>

struct Star
{
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Color color;
	float size;
	float rotation;
};

class Background
{
public:
	Background(sf::View& view);
	~Background();
	void Update(float deltaTime, float screenSize);
	void Draw(sf::RenderWindow& window);
	void CreateFrame(sf::View& view, float thickness);
	void DrawFrame(sf::RenderWindow& window);

private:
	sf::VertexArray spaceBackground;
	std::vector<Star> stars;
	std::vector<sf::RectangleShape> frame;
	std::mt19937 gen;
	std::uniform_real_distribution<float> distx;
	std::uniform_real_distribution<float> disty;
	std::uniform_real_distribution<float> dists;
	std::uniform_real_distribution<float> distr;
	std::uniform_int_distribution<int> distc;
};

