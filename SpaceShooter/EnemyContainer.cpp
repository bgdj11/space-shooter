#include "EnemyContainer.h"

EnemyContainer::EnemyContainer(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setPosition(position);
	body.setFillColor(sf::Color::Yellow);
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
}

EnemyContainer::~EnemyContainer()
{
}

void EnemyContainer::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void EnemyContainer::Color(sf::Color color)
{
	body.setFillColor(color);
}
