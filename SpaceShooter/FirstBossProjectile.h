#pragma once
#include "EnemyProjectile.h"

class FirstBossProjectile : public EnemyProjectile
{
public:
	FirstBossProjectile(sf::Texture* texture, sf::Vector2f position, float speed, bool sign);
	~FirstBossProjectile();

	void Update(float deltaTime) override;

private:
	float accumulatedTime;
	bool sign;
};

