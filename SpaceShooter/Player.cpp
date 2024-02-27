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
	health = 2;

	body.setSize(sf::Vector2f(texture->getSize().x / imageCount.x / 2.5f, texture->getSize().y / 2.5f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	body.setPosition(view.getSize().x / 2.0f, view.getSize().y - 100.0f);

	collisionBox.setSize(sf::Vector2f(body.getSize().x * 0.4f, body.getSize().y * 0.3f));
	collisionBox.setOrigin(sf::Vector2f(collisionBox.getSize().x / 2.0f, collisionBox.getSize().y / 2.0f + 30.0f));
	collisionBox.setPosition(body.getPosition());

	this->projectileTexture = projectileTexture;
}

Player::~Player()
{
}

void Player::Update(float deltaTime, sf::View& view)
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

	collisionBox.setPosition(body.getPosition());

	// PROJECTILES
	fireTimer += deltaTime;
	fireCooldown -= deltaTime;
	if (fireCooldown <=  0.0f) {
		fireCooldown = 3.0f;
		bulletCnt = 5;
	}

	for (auto& projectile : projectiles) 
	{
		projectile->Update(deltaTime);
		
		if (projectile->GetPosition().y + 100.0f < 0.0f)
			projectile->SetStatus(false);
	}
		
	projectiles.erase(
		std::remove_if(projectiles.begin(), projectiles.end(),
			[](const std::shared_ptr<PlayerProjectile>& projectile) {return !projectile->GetStatus();})
		,projectiles.end());

	// PARTICLE EXPLOSION
	for (auto& partSys : explosions)
	{
		partSys->Update(deltaTime);
	}

	explosions.erase(
		std::remove_if(explosions.begin(), explosions.end(),
			[](const std::shared_ptr<BigParticleSystem>& bigParticle) {return !bigParticle->GetStatus(); })
		, explosions.end());
}

void Player::Draw(sf::RenderWindow& window)
{
	for (auto& projectile : projectiles) {
		projectile->Draw(window);
	}

	for (auto& partSys : explosions)
	{
		partSys->Draw(window, sf::RenderStates());
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

		std::shared_ptr<PlayerProjectile> projectile = std::make_shared<PlayerProjectile>(projectileTexture, 
			sf::Vector2f(body.getPosition().x, body.getPosition().y - 25.0f), 500.0f);

		projectiles.push_back(projectile);
	}
}

std::vector<std::shared_ptr<PlayerProjectile>>& Player::GetPlayerProjectiles()
{
	return projectiles;
}

void Player::AddExplosion(std::shared_ptr<BigParticleSystem> particleSystem)
{
	explosions.push_back(particleSystem);
}

void Player::TakeDamage(int damage)
{
	health -= damage;
}

int Player::GetHealth()
{
	return health;
}
