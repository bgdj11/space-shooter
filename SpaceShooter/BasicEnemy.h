#pragma once
#include "Enemy.h"
#include <cmath>
#include "Animator.h"

class BasicEnemy : public Enemy
{
public:
	BasicEnemy(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~BasicEnemy();
	void Update(float deltaTime) override;

private:
	bool movingLeft;
	float accumulatedTime;
	bool atPosition;
	Animator animator;
};

