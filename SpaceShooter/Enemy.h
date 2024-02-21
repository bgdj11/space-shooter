#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
protected:
    int health;
	unsigned int damage;
	bool status;
	
public:
	void TakeDamage(int damage);
	int GetHealth();
	void SetStatus(bool status);
	bool GetStatus();
};

