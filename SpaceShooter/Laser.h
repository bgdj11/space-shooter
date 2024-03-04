#pragma once
#include "GameObject.h"

class Laser : public GameObject
{
public:
	Laser(sf::Texture* texture, sf::Vector2f position);
	~Laser();
	void Update(sf::Vector2f position, float delateTime);
};

