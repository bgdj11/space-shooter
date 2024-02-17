#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* texture, sf::Texture* projectileTexture, float speed)
{
	this->speed = speed;
	rotation = 0;
	fireRate = 0.3f;
	fireTimer = 0.0f;

	body.setSize(sf::Vector2f(420.0f, 300.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(500.0f, 900.0f);

	this->projectileTexture = projectileTexture;
}

Player::~Player()
{
}

void Player::Update(float deltaTime, sf::RenderWindow& window)
{
	sf::Vector2f movement(0.0f, 0.0f);
	HandleInput(deltaTime, &movement, &fireTimer);

	// ROTATION
	if (movement.x != 0.0f)
		body.setRotation(rotation);
	else
		body.setRotation(0); 

	body.move(movement);

	// SCREEN WRAPPING
	if (body.getPosition().x < 0)
		body.setPosition(window.getSize().x, body.getPosition().y);
	if (body.getPosition().x > window.getSize().x)
		body.setPosition(0.0f, body.getPosition().y);

	// PROJECTILES
	fireTimer += deltaTime;

	for (auto& projectile : projectiles) {
		projectile.Update(deltaTime);
		
		if (projectile.GetPosition() + 100.0f < 0.0f)
			projectile.SetStatus(false);
	}

	std::cout << projectiles.size() << std::endl;
		
	projectiles.erase(
		std::remove_if(projectiles.begin(), projectiles.end(),
			[](const PlayerProjectile& projectile) {return !projectile.GetStatus();})
		,projectiles.end());
}

void Player::Draw(sf::RenderWindow& window)
{
	for (auto& projectile : projectiles) {
		projectile.Draw(window);
	}

	window.draw(body);
}

void Player::HandleInput(float deltaTime, sf::Vector2f* movement, float* fireTimer)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		movement->x -= speed * deltaTime;
		rotation = -10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		movement->x += speed * deltaTime;
		rotation = 10.0f;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or sf::Mouse::isButtonPressed(sf::Mouse::Left)) && *fireTimer >= fireRate) {
		*fireTimer = 0.0f;
		PlayerProjectile projectile = PlayerProjectile(projectileTexture, body.getPosition(), 500);
		projectiles.push_back(projectile);
	}
}
