#include "entity.h"

Entity::Entity(
	Vector2 position,
	Vector2 hitboxSize,
	float speed,
	float health,
	float damage)
	:
	position(position),
	hitboxSize(hitboxSize),
	speed(speed),
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

void Entity::Update(double deltaTime) {

}

void Entity::Render() {

}