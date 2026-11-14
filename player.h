#ifndef GAMEENGINE_PLAYER_H
#define GAMEENGINE_PLAYER_H

#include <Windows.h>
#include <cmath>

#include "entity.h"

class Player : public Entity {
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