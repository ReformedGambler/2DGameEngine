#ifndef GAMEENGINE_ENTITY_H
#define GAMEENGINE_ENTITY_H

#include "vector2.h"
#include "renderer.h"

class Entity {
public:
	Vector2 position;
	Vector2 hitboxSize;
	float maxSpeed;
	float damage;
	float health;

	Entity(Vector2 position,
		   Vector2 hitboxSize,
		   float maxSpeed,
		   float health,
		   float damage
	);

	void TakeDamage(float damageTaken);
	void Heal(float healAmount);

	virtual void Update(float deltaTime);
	virtual void Render();
};

#endif