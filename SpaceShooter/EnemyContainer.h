#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class EnemyContainer : public GameObject
{
public:
	EnemyContainer(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~EnemyContainer();

	void Color(sf::Color color);

};

