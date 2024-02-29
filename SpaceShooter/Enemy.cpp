#include "Enemy.h"

std::vector<std::shared_ptr<EnemyProjectile>>& Enemy::GetProjectiles()
{
	return projectiles;
}

void Enemy::AddExplosion(std::shared_ptr<BigParticleSystem> particleSystem)
{
	explosions.push_back(particleSystem);
}

void Enemy::SetPosition(sf::Vector2f position)
{
	body.setPosition(position);
	collisionBox.setPosition(position);
}

void Enemy::Hurt()
{
	hurtTimer = 0.0f;
}

void Enemy::UpdateAppearance()
{
	appearance += 1;
}

int Enemy::GetAppearance()
{
	return appearance;
}

void Enemy::TakeDamage(int damage)
{
	health -= damage;
	Hurt();
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

