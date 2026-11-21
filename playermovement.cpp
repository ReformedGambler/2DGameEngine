#include "playermovement.h"
#include "player.h"

void PlayerMovement::KeyboardInput(float deltaTime, Player& player) {
	/* Instantiate as 0 inside scope so when stop moving,
	it does not retain previous movement values */
	float moveX{};
	float moveY{};
	float length{};
	bool flying = GetAsyncKeyState(VK_SPACE);

	// Inputs
	if (flying) {
		moveY -= 1.0f;
		player.velocityY -= player.accelerationY * player.maxFlightSpeed * deltaTime;
	}
	if (!flying) {
		// When to apply gravity (when not pressing space)
		Gravity::ApplyGravity(deltaTime, player);
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

	// Diagonal speed equalizer
	length = sqrtf(moveX * moveX + moveY * moveY);
	if (length > 0.0f) {
		moveX /= length;
		moveY /= length;
	}

	// Clamp for horizontal acceleration and deceleration movement
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

	// Clamp for vertical acceleration and deceleration movement
	player.velocityY = std::clamp(player.velocityY, -player.maxFlightSpeed, player.maxFallSpeed);
	if (moveY == 0.0f && player.velocityY < 0.0f) {
		player.velocityY += player.decelerationY * deltaTime;
		if (player.velocityY > 0.0f) {
			player.velocityY = 0.0f;
		}
	}

	// Continuously update movement
	player.position.x += player.velocityX * deltaTime;
	player.position.y += player.velocityY * deltaTime;
}

void Gravity::ApplyGravity(float deltaTime, Player& player) {
	player.velocityY += player.gravity * deltaTime;
}