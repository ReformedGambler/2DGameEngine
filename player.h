#ifndef GAMEENGINE_PLAYER_H
#define GAMEENGINE_PLAYER_H

#include <Windows.h>
#include <cmath>
#include <vector>
#include <algorithm>

#include "entity.h"
#include "playermovement.h"

class Player : public Entity {
private:
	ID2D1SolidColorBrush* brush{};
	
public:
	float velocityX{};
	float velocityY{};

	const float accelerationX{ 800.0f };
	const float decelerationX{ 400.0f };
	const float accelerationY{ 7.5f };
	const float decelerationY{ 500.0f };

	const float maxFlightSpeed{ 200.0f };
	const float maxFallSpeed{ 150.0f };
	const float gravity{ 500.0f };

	Player(Vector2 position,
		   Vector2 hitboxSize,
		   float maxSpeed,
		   float health,
		   float damage
	);

	void MouseInput();

	void Update(float deltaTime) override;
	void Render() override;

	void DebugRender();
};

#endif