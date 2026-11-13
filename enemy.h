#ifndef GAMEENGINE_ENEMY_H
#define GAMEENGINE_ENEMY_H

#include "entity.h"

class Enemy : public Entity {
public:
	void Update(double deltaTime) override;
	void Render() override;
};

#endif