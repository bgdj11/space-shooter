#include "PlayerProjectile.h"

PlayerProjectile::PlayerProjectile(sf::Texture* texture, sf::Vector2f position, float speed)
{
	this->speed = speed;
	status = true;

	body.setSize(sf::Vector2f(13.0f, 50.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);

	collisionBox.setSize(sf::Vector2f(body.getSize().x, body.getSize().y * 0.9f));
	collisionBox.setOrigin(collisionBox.getSize() / 2.0f);
	collisionBox.setPosition(body.getPosition());

	damage = 1;
}

PlayerProjectile::~PlayerProjectile()
{
}

void PlayerProjectile::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	movement.y -= speed * deltaTime;
	body.move(movement);
	collisionBox.move(movement);
}

sf::Vector2f PlayerProjectile::GetPosition()
{
	return body.getPosition();
}

bool PlayerProjectile::GetStatus() const
{
	return status;
}

void PlayerProjectile::SetStatus(bool status)
{
	this->status = status;
}

int PlayerProjectile::GetDamage()
{
	return damage;
}

void PlayerProjectile::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
