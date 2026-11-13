#include "entity.h"

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