#include "BasicEnemy.h"

BasicEnemy::BasicEnemy(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Texture* projectileTexture)
	: animator(texture, sf::Vector2u(4, 1), 0.1f)
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);
	std::uniform_real_distribution<> disFire(1.5f, 7.5f);

	health = 3;
	damage = 1;
	speed = 200.0f;
	status = true;
	fireCooldown = disFire(gen);
	fireTimer = 0.0f;
	hurtTimer = 0.2f;

	body.setSize(size);
	body.setPosition(sf::Vector2f(position.x, -420.0f));
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);

	collisionBox.setSize(sf::Vector2f(body.getSize().x * 0.2f, body.getSize().y * 0.5f));
	collisionBox.setFillColor(sf::Color::Red);
	collisionBox.setOrigin(collisionBox.getSize() / 2.0f);
	collisionBox.setPosition(body.getPosition());

	basePosition = position;
	accumulatedTime = 0.0f;
	atPosition = false;
	movingLeft = false;

	//movingLeft = dis(gen) == 0 ? false : true;

	this->projectileTexture = projectileTexture;
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
		fireTimer += deltaTime;
		if (fireTimer >= fireCooldown)
		{
			std::shared_ptr<EnemyProjectile> projectile = std::make_shared<EnemyProjectile>(projectileTexture,
				sf::Vector2f(body.getPosition().x, body.getPosition().y - 25.0f), 500.0f);
			projectiles.push_back(projectile);

			fireTimer = 0.0f;
		}

		for (auto& projectile : projectiles)
		{
			projectile->Update(deltaTime);

			if (projectile->GetPosition().y > 1800.0f)
				projectile->SetStatus(false);
		}

		projectiles.erase(
			std::remove_if(projectiles.begin(), projectiles.end(),
				[](const std::shared_ptr<EnemyProjectile>& projectile) {return !projectile->GetStatus(); })
			, projectiles.end());

		// PARTICLE EXPLOSION
		for (auto& partSys : explosions)
		{
			partSys->Update(deltaTime);
		}

		explosions.erase(
			std::remove_if(explosions.begin(), explosions.end(),
				[](const std::shared_ptr<BigParticleSystem>& bigParticle) {return !bigParticle->GetStatus(); })
			, explosions.end());

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
		}

		// movement.x = 0.5f * sin(accumulatedTime * 0.5f);
		movement.y = 0.2f * sin(accumulatedTime * 5);
		body.move(movement);
		collisionBox.move(movement);
	}

	hurtTimer += deltaTime;
	if (hurtTimer < 0.2f)
		body.setFillColor(sf::Color::Red);
	else
		body.setFillColor(sf::Color::White);

}

void BasicEnemy::Draw(sf::RenderWindow& window)
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

