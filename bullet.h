#ifndef GAMEENGINE_BULLET_H
#define GAMEENGINE_BULLET_H

#include "vector2.h"
#include "window.h"		// For IsOffScreen()
#include "renderer.h"

class Bullet {
public:
	Vector2 position;
	Vector2 hitboxSize;
	float maxSpeed;
	float damage;

	float velocityX{};
	float velocityY{};

	Bullet(Vector2 position,
		   Vector2 hitboxSize,
		   float maxSpeed,
		   float damage
	);

	bool IsOffScreen() const;

	//void Update(double deltaTime) override;
	//void Render() override;

	void DebugRender();
};

#endif