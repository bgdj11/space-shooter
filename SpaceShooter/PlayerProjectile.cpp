#include "PlayerProjectile.h"

PlayerProjectile::PlayerProjectile(sf::Texture* texture, sf::Vector2f position, float speed)
	: particleSystem(10, 0.48f)
{
	this->speed = speed;
	status = true;

	body.setSize(sf::Vector2f(12.0f, 35.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);

	damage = 1;

	// PARTICLE SYSTEM
	for (unsigned i = 0; i < 10; i++) {
		sf::Vector2f velocity(rand() % 100 - 50, rand() % 100 - 50);
		particleSystem.AddParticle(body.getPosition(), velocity, sf::Color(255, 94, 0));
	}
}

PlayerProjectile::~PlayerProjectile()
{
}

void PlayerProjectile::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	movement.y -= speed * deltaTime;
	body.move(movement);
	
	for (int i = 0; i < 2; i++) {
		sf::Vector2f velocity((rand() % 100 - 50) * 2, rand() % 100 - 50);
		particleSystem.AddParticle(body.getPosition(), velocity, sf::Color(52, 235, 225));
	}

	particleSystem.Update(deltaTime, body.getPosition(), sf::Vector2f(0.0f, speed));
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

int PlayerProjectile::GetDamage()
{
	return damage;
}

void PlayerProjectile::Draw(sf::RenderWindow& window)
{
	particleSystem.Draw(window, sf::RenderStates());
	window.draw(body);
}
