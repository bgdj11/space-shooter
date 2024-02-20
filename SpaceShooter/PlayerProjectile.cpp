#include "PlayerProjectile.h"

PlayerProjectile::PlayerProjectile(sf::Texture* texture, sf::Vector2f position, float speed)
{
	this->speed = speed;
	status = true;

	body.setSize(sf::Vector2f(14.0f, 55.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}

PlayerProjectile::~PlayerProjectile()
{
}

void PlayerProjectile::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	movement.y -= speed * deltaTime;
	body.move(movement);
}

void PlayerProjectile::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

float PlayerProjectile::GetPosition()
{
	return body.getPosition().y;
}

bool PlayerProjectile::GetStatus() const
{
	return status;
}

void PlayerProjectile::SetStatus(bool status)
{
	this->status = status;
}

Collider PlayerProjectile::GetCollider()
{
	return Collider(body);
}

