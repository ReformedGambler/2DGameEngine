#ifndef GAMEENGINE_PLAYER_H
#define GAMEENGINE_PLAYER_H

#include <Windows.h>
#include <cmath>
#include <vector>
#include <algorithm>

#include "entity.h"
#include "bullet.h"

class Player : public Entity {
private:
	float shootTimer{};
	std::vector<Bullet> bullets;
	ID2D1SolidColorBrush* brush{};
public:
	float velocityX{};
	float velocityY{};
	float accelerationX{ 800.0f };
	float decelerationX{ 400.0f };
	//float accelerationY{};
	//float decelerationY{};

	Player(Vector2 position,
		   Vector2 hitboxSize,
		   float speed,
		   float health,
		   float damage
	);

	void MouseInput();
	void KeyboardInput(float deltaTime);

	void Update(float deltaTime) override;
	void Render() override;

	void DebugRender();
};

#endif