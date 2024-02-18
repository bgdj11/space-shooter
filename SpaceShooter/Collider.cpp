#include "Collider.h"

Collider::Collider(sf::RectangleShape& collisionBox) : collisionBox(collisionBox)
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider other)
{
	sf::Vector2f thisPosition = this->GetPosition();
	sf::Vector2f thisHalfSize = this->GetHalfSize();
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (thisHalfSize.x + otherHalfSize.x);
	float intersectY = abs(deltaY) - (thisHalfSize.y + otherHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
		return true;

	return false;
}

sf::Vector2f Collider::GetPosition()
{
	return collisionBox.getPosition();
}

sf::Vector2f Collider::GetHalfSize()
{
	return collisionBox.getSize() / 2.0f;
}

void Collider::Move(float dx, float dy)
{
	collisionBox.move(dx, dy);
}
