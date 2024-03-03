#include "FirstBoss.h"

FirstBoss::FirstBoss(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Texture* projectileTexture)
	: animator(texture, sf::Vector2u(4, 1), 0.1f)
{
	health = 10;
	damage = 3;
	speed = 200.0f;
	status = true;
	hurtTimer = 0.2f;
	atPosition = false;
	basePosition = position;
	movingLeft = false;
	accumulatedTime = 0.0f;
	boss = true;
	fireCooldown = 2.0f;
	fireTimer = 0.0f;

	body.setSize(size);
	body.setPosition(sf::Vector2f(position.x, -620.0f));
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);

	collisionBox.setSize(sf::Vector2f(body.getSize().x * 0.2f, body.getSize().y * 0.6f));
	collisionBox.setOrigin(collisionBox.getSize() / 2.0f);
	collisionBox.setPosition(body.getPosition());

	this->projectileTexture = projectileTexture;
}

FirstBoss::~FirstBoss()
{
}

void FirstBoss::Update(float deltaTime)
{
	hurtTimer += deltaTime;
	if (hurtTimer < 0.2f)
		body.setFillColor(sf::Color::Red);
	else
		body.setFillColor(sf::Color::White);

	// Animator
	animator.Update(0, deltaTime);
	body.setTextureRect(animator.uvRect);

	sf::Vector2f movement(0.0f, 0.0f);

	accumulatedTime += deltaTime;

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
			std::shared_ptr<EnemyProjectile> projectile1 = std::make_shared<FirstBossProjectile>(projectileTexture,
				sf::Vector2f(body.getPosition().x, body.getPosition().y - 25.0f), 300.0f, false);
			projectiles.push_back(projectile1);

			std::shared_ptr<EnemyProjectile> projectile2 = std::make_shared<FirstBossProjectile>(projectileTexture,
				sf::Vector2f(body.getPosition().x, body.getPosition().y - 25.0f), 300.0f, true);
			projectiles.push_back(projectile2);

			fireTimer = 0.0f;
		}

		for (auto& projectile : projectiles)
		{
			projectile->Update(deltaTime);

			if (projectile->GetPosition().y > 1500.0f)
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

		movement.y = 0.2f * sin(accumulatedTime * 5);
		body.move(movement);
		collisionBox.move(movement);
	}
}

void FirstBoss::Draw(sf::RenderWindow& window)
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
