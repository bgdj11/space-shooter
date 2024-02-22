#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
protected:
    int health;
	unsigned int damage;
	bool status;
	float speed;
	sf::Vector2f basePosition;
	
public:
	void TakeDamage(int damage);
	int GetHealth();
	void SetStatus(bool status);
	bool GetStatus();
	virtual void Update(float deltaTime);
};

