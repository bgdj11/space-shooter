#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class PlayerProjectile : public GameObject
{
public:
	PlayerProjectile(sf::Texture* texture, sf::Vector2f position, float speed);
	~PlayerProjectile();

	void Update(float deltaTime);
	float GetPosition();
	bool GetStatus() const;
	void SetStatus(bool status);

private:
	float speed;
	bool status;
};

