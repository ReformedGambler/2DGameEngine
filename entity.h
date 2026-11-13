#ifndef GAMEENGINE_ENTITY_H
#define GAMEENGINE_ENTITY_H

#include "vector2.h"

class Entity {
public:
	Vector2 position;
	Vector2 hitboxSize;

	float health;
	float damage;
	float speed;

	void TakeDamage(float damageTaken);
	void Heal(float healAmount);

	virtual void Update(double deltaTime);
	virtual void Render();
};

#endif