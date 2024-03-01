#include "FirstBossProjectile.h"

FirstBossProjectile::FirstBossProjectile(sf::Texture* texture, sf::Vector2f position, float speed, bool sign)
	: EnemyProjectile(texture, position, speed)
{
	this->speed = speed;
	status = true;
	damage = 2;
	accumulatedTime = 0.0f;
	this->sign = sign;

	body.setSize(sf::Vector2f(30.0f, 40.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
	body.setFillColor(sf::Color::Yellow);

	collisionBox.setSize(sf::Vector2f(body.getSize().x, body.getSize().y * 0.9f));
	collisionBox.setOrigin(collisionBox.getSize() / 2.0f);
	collisionBox.setPosition(body.getPosition());
}

FirstBossProjectile::~FirstBossProjectile()
{
}

void FirstBossProjectile::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	movement.y = speed * deltaTime;

	accumulatedTime += deltaTime;
	
	if(sign)
		movement.x = 2.5f * cos(accumulatedTime * 10);
	else
		movement.x = -2.5f * cos(accumulatedTime * 10);

	body.move(movement);
	collisionBox.move(movement);
}
