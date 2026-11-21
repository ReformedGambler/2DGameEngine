#ifndef GAMEENGINE_ENTITY_H
#define GAMEENGINE_ENTITY_H

#include "vector2.h"
#include "renderer.h"

class Entity {
public:
	Entity(Vector2 position,
		   Vector2 hitboxSize,
		   float speed,
		   float health,
		   float damage
	);

	Vector2 position;
	Vector2 hitboxSize;

	float health;
	float damage;
	float speed;

	void TakeDamage(float damageTaken);
	void Heal(float healAmount);

	virtual void Update(float deltaTime);
	virtual void Render();
};

#endif