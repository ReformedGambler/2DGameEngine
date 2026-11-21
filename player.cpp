#include "player.h"

Player::Player(
	Vector2 position,
	Vector2 hitboxSize,
	float speed,
	float health,
	float damage)
	:
	Entity(position,
		   hitboxSize,
		   speed,
		   health,
		   damage) {
	// Initialize brush to solid black brush
	renderTarget->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::Black),
		&brush
	);
}

void Player::MouseInput() {

}

void Player::KeyboardInput(float deltaTime) {
	float moveX{};
	float moveY{};
	float length{};

	if (GetAsyncKeyState('W')) {
		moveY -= 1.0f;
	}
	if (GetAsyncKeyState('A')) {
		moveX -= 1.0f;
		velocityX -= accelerationX * deltaTime;
	}
	if (GetAsyncKeyState('S')) {
		moveY += 1.0f;
	}
	if (GetAsyncKeyState('D')) {
		moveX += 1.0f;
		velocityX += accelerationX * deltaTime;
	}

	length = sqrtf(moveX * moveX + moveY * moveY);
	if (length > 0.0f) {
		moveX /= length;
		moveY /= length;
	}

	velocityX = std::clamp(velocityX, -speed, speed);
	if (moveX == 0.0f && velocityX > 0.0f) {
		velocityX -= decelerationX * deltaTime;
		if (velocityX < 0.0f) {
			velocityX = 0.0f;
		}
	}
	if (moveX == 0.0f && velocityX < 0.0f) {
		velocityX += decelerationX * deltaTime;
		if (velocityX > 0.0f) {
			velocityX = 0.0f;
		}
	}
	
	position.x += velocityX * deltaTime;
	position.y += moveY * speed * deltaTime;
}

void Player::Update(float deltaTime) {
	KeyboardInput(deltaTime);
}

void Player::Render() {

}

void Player::DebugRender() {
	// Fill rectangle configurations
	D2D1_RECT_F rect = D2D1::RectF(
		position.x,
		position.y,
		position.x + hitboxSize.x,
		position.y + hitboxSize.y
	);

	// Draw rectangle
	renderTarget->DrawRectangle(
		rect,
		brush,
		1.0f
	);
}