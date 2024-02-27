#include "BasicEnemy.h"

BasicEnemy::BasicEnemy(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	health = 3;
	damage = 1;
	speed = 200.0f;
	status = true;

	body.setSize(size);
	body.setPosition(sf::Vector2f(position.x, position.y - 400.0f));
	body.setFillColor(sf::Color(3, 252, 132));
	//body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);

	collisionBox.setSize(sf::Vector2f(body.getSize().x * 0.8f, body.getSize().y * 0.8f));
	collisionBox.setOrigin(collisionBox.getSize() / 2.0f);
	collisionBox.setPosition(body.getPosition());

	basePosition = position;
	movingLeft = true;
	accumulatedTime = 0.0f;
	atPosition = false;
}

BasicEnemy::~BasicEnemy()
{
}

void BasicEnemy::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	
	accumulatedTime += deltaTime;

	if (!atPosition)
	{
		movement.y += 300.0f * deltaTime;

		body.move(movement);
		collisionBox.move(movement);

		if (std::abs(body.getPosition().y - basePosition.y) <= 10.0f)
			atPosition = true;
	}
	else
	{
		if (movingLeft)
		{
			if (body.getPosition().x <= basePosition.x - 100.0f)
			{
				movement.x += speed * deltaTime;
				movingLeft = false;
			}
			else
			{
				movement.x -= speed * deltaTime;
			}
		}
		else
		{
			if (body.getPosition().x >= basePosition.x + 100.0f)
			{
				movement.x -= speed * deltaTime;
				movingLeft = true;
			}
			else
			{
				movement.x += speed * deltaTime;
			}
		}

		// movement.x = 0.5f * sin(accumulatedTime * 0.5f);
		movement.y = 0.5f * sin(accumulatedTime * 5);
		body.move(movement);
		collisionBox.move(movement);
	}
}
