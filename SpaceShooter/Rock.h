#pragma once
#include "Enemy.h"

class Rock : public Enemy
{
public:
	Rock(sf::Texture* texture, sf::Vector2f size);
	~Rock();
	void Update(float deltaTime) override;

private:
	float rotationSpeed;
};

