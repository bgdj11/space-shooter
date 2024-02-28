#include "FirstBoss.h"

FirstBoss::FirstBoss(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	health = 5;
	damage = 3;
	speed = 200.0f;
	status = true;
	hurtTimer = 0.2f;

	body.setSize(size);
	body.setPosition(position);
	//body.setFillColor(sf::Color(16, 115, 37));
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);

	collisionBox.setSize(sf::Vector2f(body.getSize().x * 0.8f, body.getSize().y * 0.8f));
	collisionBox.setOrigin(collisionBox.getSize() / 2.0f);
	collisionBox.setPosition(body.getPosition());
}

FirstBoss::~FirstBoss()
{
}

void FirstBoss::Update(float deltaTime)
{
	// find out !?
	hurtTimer += deltaTime;
	if (hurtTimer < 0.2f)
		body.setFillColor(sf::Color::Red);
	else
		body.setFillColor(sf::Color::White);
}
