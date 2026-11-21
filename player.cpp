#include "player.h"

Player::Player(
	Vector2 position,
	Vector2 hitboxSize,
	float maxSpeed,
	float health,
	float damage)
	:
	Entity(position,
		   hitboxSize,
		   maxSpeed,
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

void Player::Update(float deltaTime) {
	PlayerMovement::KeyboardInput(deltaTime, *this);
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