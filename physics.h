#ifndef GAMEENGINE_PHYSICS_H
#define GAMEENGINE_PHYSICS_H

class Entity;

class Physics {
public:
	void ApplyGravity(float deltaTime, Entity& entity);
};

#endif