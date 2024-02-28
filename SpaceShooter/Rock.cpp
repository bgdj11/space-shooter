#include "Rock.h"
#include <iostream>
#include <random>

Rock::Rock(sf::Texture* texture, sf::Vector2f size, float viewSizeX)
{
	health = 3;
	damage = 1;
	speed = 450.0f;
	status = true;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> distrx(30.0f, viewSizeX - 30.0f);
	std::uniform_real_distribution<float> distry(-8000.0f, -600.0f);
	std::uniform_real_distribution<float> distr(10.0, 60.0f);

	rotationSpeed = distr(gen);

	body.setSize(size);
	body.setPosition(sf::Vector2f(distrx(gen), distry(gen)));
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);

	collisionBox.setSize(sf::Vector2f(body.getSize().x * 0.8f, body.getSize().y * 0.8f));
	collisionBox.setOrigin(collisionBox.getSize() / 2.0f);
	collisionBox.setPosition(body.getPosition());
}

Rock::~Rock()
{
}

void Rock::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	movement.y = speed * deltaTime;

	body.rotate(rotationSpeed * deltaTime);
	body.move(movement);
	collisionBox.move(movement);
}
