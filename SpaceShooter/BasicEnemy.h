#pragma once
#include "Enemy.h"

class BasicEnemy : public Enemy
{
public:
	BasicEnemy(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~BasicEnemy();
	void Update() override;

};

