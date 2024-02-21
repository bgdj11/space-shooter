#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* texture, sf::Texture* projectileTexture, float speed, sf::View& view, sf::Vector2u imageCount, float switchTime)
		: animator(texture, imageCount, switchTime)
{
	this->speed = speed;
	rotation = 0;
	fireRate = 0.2f;
	fireTimer = 0.0f;
	fireCooldown = 3.0f;
	bulletCnt = 5;

	body.setSize(sf::Vector2f(texture->getSize().x / imageCount.x / 2.5f, texture->getSize().y / 2.5f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(view.getSize().x / 2.0f, view.getSize().y - 100.0f);

	this->projectileTexture = projectileTexture;
}

Player::~Player()
{
}

void Player::Update(float deltaTime, sf::View& view, EnemyContainer* enemy)
{
	body.setPosition(body.getPosition().x, view.getSize().y - 100.0f);

	sf::Vector2f movement(0.0f, 0.0f);
	HandleInput(deltaTime, &movement, &fireTimer, &bulletCnt);

	// ANIMATION
	animator.Update(0, deltaTime);
	body.setTextureRect(animator.uvRect);

	// ROTATION
	if (movement.x != 0.0f)
		body.setRotation(rotation);
	else
		body.setRotation(0); 

	body.move(movement);

	// SCREEN WRAPPING
	if (body.getPosition().x < 0)
		body.setPosition(view.getSize().x, body.getPosition().y);
	if (body.getPosition().x > view.getSize().x)
		body.setPosition(0.0f, body.getPosition().y);

	// PROJECTILES
	fireTimer += deltaTime;
	fireCooldown -= deltaTime;
	if (fireCooldown <=  0.0f) {
		fireCooldown = 3.0f;
		bulletCnt = 5;
	}

	for (auto& projectile : projectiles) {
		projectile.Update(deltaTime);
		
		if (projectile.GetPosition() + 100.0f < 0.0f)
			projectile.SetStatus(false);

		// collision detection
		if (enemy->GetCollider().CheckCollision(projectile.GetCollider())) {
			enemy->Color(sf::Color::Blue);
		}
	}
		
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

void Player::HandleInput(float deltaTime, sf::Vector2f* movement, float* fireTimer, int* bulletCnt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		movement->x -= speed * deltaTime;
		rotation = -10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		movement->x += speed * deltaTime;
		rotation = 10.0f;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or sf::Mouse::isButtonPressed(sf::Mouse::Left)) && *fireTimer >= fireRate && *bulletCnt > 0) {
		*bulletCnt -= 1;
		*fireTimer = 0.0f;

		PlayerProjectile projectile = PlayerProjectile(projectileTexture, sf::Vector2f(body.getPosition().x, body.getPosition().y - 25), 500);
		projectiles.push_back(projectile);
	}
}
