#pragma once
#include "Enemy.h"
#include "Animator.h"

class FirstBoss : public Enemy
{
public:
	FirstBoss(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~FirstBoss();
	void Update(float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

private:
	Animator animator;
	bool atPosition;
	bool movingLeft;
	float accumulatedTime;
};

