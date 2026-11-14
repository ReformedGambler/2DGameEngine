#ifndef GAMEENGINE_BULLET_H
#define GAMEENGINE_BULLET_H

#include "entity.h"

class Bullet : public Entity {
public:
	Bullet(Vector2 position,
		   Vector2 hitboxSize,	// 5.0f, 10.0f
		   float speed,
		   float health,
		   float damage
	);

	void Update(double deltaTime) override;
	void Render() override;

	void DebugRender();
};

#endif