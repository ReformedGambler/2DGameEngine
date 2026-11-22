#ifndef GAMEENGINE_BULLET_H
#define GAMEENGINE_BULLET_H

#include "vector2.h"
#include "window.h"		// For IsOffScreen()
#include "renderer.h"

#include <wrl/client.h>

class Bullet {
public:
	Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> brush{ nullptr };

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

	void DebugRender();
};

#endif