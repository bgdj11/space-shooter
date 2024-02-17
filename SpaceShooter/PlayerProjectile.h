#pragma once
#include <SFML/Graphics.hpp>

class PlayerProjectile
{
public:
	PlayerProjectile(sf::Texture* texture, sf::Vector2f position, float speed);
	~PlayerProjectile();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	float GetPosition();
	bool GetStatus() const;
	void SetStatus(bool status);

private:
	sf::RectangleShape body;
	float speed;
	bool status;
};

