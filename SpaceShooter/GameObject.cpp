#include "GameObject.h"

GameObject::GameObject()
{
}

void GameObject::Update()
{
}

void GameObject::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

Collider GameObject::GetCollider()
{
	return Collider(collisionBox); 
}
