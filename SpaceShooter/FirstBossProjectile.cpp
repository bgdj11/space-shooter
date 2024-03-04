#include "FirstBossProjectile.h"

FirstBossProjectile::FirstBossProjectile(sf::Texture* texture, sf::Vector2f position, float speed, bool sign)
	: EnemyProjectile(texture, position, speed), animator(texture, sf::Vector2u(4, 1), 0.1f)
{
	this->speed = speed;
	status = true;
	damage = 2;
	accumulatedTime = 0.0f;
	this->sign = sign;

	body.setSize(sf::Vector2f(50.0f, 38.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
	//body.setFillColor(sf::Color::Yellow);

	collisionBox.setSize(sf::Vector2f(body.getSize().x, body.getSize().y * 0.9f));
	collisionBox.setOrigin(collisionBox.getSize() / 2.0f);
	collisionBox.setPosition(body.getPosition());
}

FirstBossProjectile::~FirstBossProjectile()
{
}

void FirstBossProjectile::Update(float deltaTime)
{
	animator.Update(0, deltaTime);
	body.setTextureRect(animator.uvRect);

	sf::Vector2f movement(0.0f, 0.0f);
	movement.y = speed * deltaTime;

	accumulatedTime += deltaTime;
	
	if(sign)
		movement.x = 2.0f * cos(accumulatedTime * 8);
	else
		movement.x = -2.0f * cos(accumulatedTime * 8);

	body.move(movement);
	body.rotate(20.0f);
	collisionBox.move(movement);
}
