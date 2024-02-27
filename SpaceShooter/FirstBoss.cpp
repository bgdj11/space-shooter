#include "FirstBoss.h"

FirstBoss::FirstBoss(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	health = 10;
	damage = 3;
	speed = 200.0f;
	status = true;

	body.setSize(size);
	body.setPosition(position);
	body.setFillColor(sf::Color(16, 115, 37));
	//body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
}

FirstBoss::~FirstBoss()
{
}

void FirstBoss::Update(float deltaTime)
{
	// find out !?
}
