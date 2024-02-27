#include "Enemy.h"

void Enemy::TakeDamage(int damage)
{
	health -= damage;
}

int Enemy::GetHealth()
{
	return health;
}

int Enemy::GetDamage()
{
	return damage;
}

void Enemy::SetStatus(bool status)
{
	this->status = status;
}

bool Enemy::GetStatus()
{
	return status;
}

void Enemy::Update(float deltaTime)
{
}

sf::Vector2f Enemy::GetPosition()
{
	return body.getPosition();
}

