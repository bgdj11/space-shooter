#include "EnemyProjectile.h"

EnemyProjectile::EnemyProjectile(sf::Texture* texture, sf::Vector2f position, float speed)
{
	this->speed = speed;
	status = true;
	damage = 1;

	body.setSize(sf::Vector2f(30.0f, 30.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);

	collisionBox.setSize(sf::Vector2f(body.getSize().x, body.getSize().y * 0.9f));
	collisionBox.setOrigin(collisionBox.getSize() / 2.0f);
	collisionBox.setPosition(body.getPosition());
}

EnemyProjectile::~EnemyProjectile()
{
}

void EnemyProjectile::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	movement.y = speed * deltaTime;
	body.move(movement);
	collisionBox.move(movement);
}

sf::Vector2f EnemyProjectile::GetPosition()
{
	return body.getPosition();
}

bool EnemyProjectile::GetStatus() const
{
	return status;
}

void EnemyProjectile::SetStatus(bool status)
{
	this->status = status;
}

int EnemyProjectile::GetDamage()
{
	return damage;
}

void EnemyProjectile::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
