#ifndef GAMEENGINE_PLAYER_H
#define GAMEENGINE_PLAYER_H

#include <Windows.h>
#include <cmath>

#include "entity.h"
#include "renderer.h"

class Player : public Entity {
public:
	Player();

	void MouseInput();
	void KeyboardInput(double deltaTime);

	void Update(double deltaTime) override;
	void Render() override;

	void DebugRender();
};

#endif