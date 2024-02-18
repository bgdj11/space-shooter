#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& collisionBox);
	~Collider();

	bool CheckCollision(Collider other);
	sf::Vector2f GetPosition();
	sf::Vector2f GetHalfSize();

	void Move(float dx, float dy);

private:
	sf::RectangleShape& collisionBox;

};

