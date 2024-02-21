#include "BasicEnemy.h"

BasicEnemy::BasicEnemy(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	health = 3;
	damage = 1;

	body.setSize(size);
	body.setPosition(position);
	body.setFillColor(sf::Color::Green);
	//body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
}

BasicEnemy::~BasicEnemy()
{
}

void BasicEnemy::Update()
{
}
