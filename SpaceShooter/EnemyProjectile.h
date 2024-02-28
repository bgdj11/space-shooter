#pragma once
#include "GameObject.h"

class EnemyProjectile : public GameObject
{
public:
	EnemyProjectile(sf::Texture* texture, sf::Vector2f position, float speed);
	~EnemyProjectile();
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

