#include "Rock.h"
#include <iostream>
#include <random>

Rock::Rock(sf::Texture* texture, sf::Vector2f size)
{
	health = 3;
	damage = 1;
	speed = 450.0f;
	status = true;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> distrx(30.0f, 970.0f);
	std::uniform_real_distribution<float> distry(-5000.0f, -300.0f);
	std::uniform_real_distribution<float> distr(10.0, 40.0f);

	rotationSpeed = distr(gen);

	body.setSize(size);
	body.setPosition(sf::Vector2f(distrx(gen), distry(gen)));
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);
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
}
