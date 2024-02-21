#include "FirstBoss.h"

FirstBoss::FirstBoss(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	health = 10;
	damage = 3;

	body.setSize(size);
	body.setPosition(position);
	body.setFillColor(sf::Color::Green);
	//body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
}

FirstBoss::~FirstBoss()
{
}

void FirstBoss::Update()
{
	// find out !?
}
