#ifndef GAMEENGINE_BULLET_H
#define GAMEENGINE_BULLET_H

#include "entity.h"		// For Inheritance
#include "window.h"		// For IsOffScreen()

class Bullet : public Entity {
public:
	float velocityX{};
	float velocityY{};

	Bullet(Vector2 position,
		   Vector2 hitboxSize,
		   float speed,
		   float health,
		   float damage
	);

	bool IsOffScreen() const;

	void Update(double deltaTime) override;
	void Render() override;

	void DebugRender();
};

#endif