#pragma once
#include "Enemy.h"

class FirstBoss : public Enemy
{
public:
	FirstBoss(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~FirstBoss();
	void Update(float deltaTime) override;

};

