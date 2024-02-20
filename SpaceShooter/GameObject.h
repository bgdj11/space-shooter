#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class GameObject
{
protected:
	sf::RectangleShape body;
	sf::RectangleShape collisionBox;

public:

	GameObject();
	virtual void Update();
	virtual void Draw(sf::RenderWindow& window);
	Collider GetCollider();

};

