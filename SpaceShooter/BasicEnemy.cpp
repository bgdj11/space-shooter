#include "BasicEnemy.h"

BasicEnemy::BasicEnemy(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
	: animator(texture, sf::Vector2u(4, 1), 0.1f)
{
	health = 3;
	damage = 1;
	speed = 200.0f;
	status = true;

	body.setSize(size);
	body.setPosition(sf::Vector2f(position.x, -420.0f));
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);

	collisionBox.setSize(sf::Vector2f(body.getSize().x * 0.2f, body.getSize().y * 0.5f));
	collisionBox.setFillColor(sf::Color::Red);
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

	// Animator
	animator.Update(0, deltaTime);
	body.setTextureRect(animator.uvRect);

	if (!atPosition)
	{
		movement.y += 300.0f * deltaTime;

		body.move(movement);
		collisionBox.move(movement);

		if (std::abs(body.getPosition().y - basePosition.y) <= 7.0f)
			atPosition = true;
	}
	else
	{
		if (movingLeft)
		{
			if (body.getPosition().x <= basePosition.x - 200.0f)
			{
				movement.x += speed * deltaTime;
				movingLeft = false;
			}
			else
			{
				movement.x -= speed * deltaTime;
			}
			body.setRotation(10);
		}
		else
		{
			if (body.getPosition().x >= basePosition.x + 200.0f)
			{
				movement.x -= speed * deltaTime;
				movingLeft = true;
			}
			else
			{
				movement.x += speed * deltaTime;
			}
			body.setRotation(-10);
		}

		// movement.x = 0.5f * sin(accumulatedTime * 0.5f);
		movement.y = 0.2f * sin(accumulatedTime * 5);
		body.move(movement);
		collisionBox.move(movement);
	}
}
