#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class EnemyContainer
{
public:
	EnemyContainer(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~EnemyContainer();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }

	void Color(sf::Color color);

private:
	sf::RectangleShape body;

};

