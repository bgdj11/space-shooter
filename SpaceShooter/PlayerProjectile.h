#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "ParticleSystem.h"

class PlayerProjectile : public GameObject
{
public:
	PlayerProjectile(sf::Texture* texture, sf::Vector2f position, float speed);
	~PlayerProjectile();

	void Update(float deltaTime);
	sf::Vector2f GetPosition();
	bool GetStatus() const;
	void SetStatus(bool status);
	int GetDamage();
	void Draw(sf::RenderWindow& window) override;

private:
	float speed;
	bool status;
	int damage;
};

