#include "Laser.h"

Laser::Laser(sf::Texture* texture, sf::Vector2f position)
{
	body.setSize(sf::Vector2f(20.0f, 1500.0f));
	body.setTexture(texture);
	body.setOrigin(sf::Vector2f(body.getSize().x / 2.0f, body.getSize().y));
	body.setPosition(position);

	collisionBox.setSize(body.getSize());
	collisionBox.setOrigin(sf::Vector2f(body.getSize().x / 2.0f, body.getSize().y));
	collisionBox.setPosition(body.getPosition());
}

Laser::~Laser()
{
}

void Laser::Update(sf::Vector2f position, float delateTime)
{
	body.setPosition(position);
	collisionBox.setPosition(position);
}
