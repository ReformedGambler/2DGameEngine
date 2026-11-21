#include "entity.h"

Entity::Entity(
	Vector2 position,
	Vector2 hitboxSize,
	float maxSpeed,
	float health,
	float damage)
	:
	position(position),
	hitboxSize(hitboxSize),
	maxSpeed(maxSpeed),
	health(health),
	damage(damage)
	{

}

void Entity::TakeDamage(float damageTaken) {
	health -= damageTaken;
}

void Entity::Heal(float healAmount) {
	health += healAmount;
}

void Entity::Update(float deltaTime) {

}

void Entity::Render() {

}