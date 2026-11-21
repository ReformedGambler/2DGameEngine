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
	float accelerationX{ 800.0f };
	float decelerationX{ 400.0f };
	float accelerationY{};
	float decelerationY{};

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