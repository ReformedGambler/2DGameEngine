#ifndef GAMEENGINE_PLAYER_H
#define GAMEENGINE_PLAYER_H

#include <Windows.h>
#include <cmath>

#include <vector>

#include "entity.h"
#include "bullet.h"

class Player : public Entity {
private:
	float shootTimer{};
	std::vector<Bullet> bullets;
	ID2D1SolidColorBrush* brush{};
public:
	Player(Vector2 position,
		   Vector2 hitboxSize,
		   float speed,
		   float health,
		   float damage
	);

	void MouseInput();
	void KeyboardInput(double deltaTime);

	void Update(double deltaTime) override;
	void Render() override;

	void DebugRender();
};

#endif