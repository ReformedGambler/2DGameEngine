#include "playermovement.h"
#include "player.h"

void PlayerMovement::KeyboardInput(float deltaTime, Player& player) {
	float moveX{};
	float moveY{};
	float length{};

	if (GetAsyncKeyState('W')) {
		moveY -= 1.0f;
	}
	if (GetAsyncKeyState('A')) {
		moveX -= 1.0f;
		player.velocityX -= player.accelerationX * deltaTime;
	}
	if (GetAsyncKeyState('S')) {
		moveY += 1.0f;
	}
	if (GetAsyncKeyState('D')) {
		moveX += 1.0f;
		player.velocityX += player.accelerationX * deltaTime;
	}

	length = sqrtf(moveX * moveX + moveY * moveY);
	if (length > 0.0f) {
		moveX /= length;
		moveY /= length;
	}

	player.velocityX = std::clamp(player.velocityX, -player.maxSpeed, player.maxSpeed);
	if (moveX == 0.0f && player.velocityX > 0.0f) {
		player.velocityX -= player.decelerationX * deltaTime;
		if (player.velocityX < 0.0f) {
			player.velocityX = 0.0f;
		}
	}
	if (moveX == 0.0f && player.velocityX < 0.0f) {
		player.velocityX += player.decelerationX * deltaTime;
		if (player.velocityX > 0.0f) {
			player.velocityX = 0.0f;
		}
	}

	player.position.x += player.velocityX * deltaTime;
	player.position.y += moveY * player.maxSpeed * deltaTime;
}