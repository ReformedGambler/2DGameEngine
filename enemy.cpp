#include "enemy.h"

Enemy::Enemy(
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
	// Initialize brush to solid red brush
	renderTarget->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::Red),
		&brush
	);
}

void Enemy::TestAttack_1(float deltaTime) {
	spiral.Continuous(
		deltaTime,
		0.001f,
		spiral.bullets,
		position,
		hitboxSize,
		Vector2(2.5f, 2.5f),
		1,
		200.0f,
		angleIncrement
	);
	spiral.Update(deltaTime, spiral.bullets, 1.0f);
	angleIncrement += angleIncrementOffset;
}

void Enemy::Update(float deltaTime) {
	TestAttack_1(deltaTime);
}

void Enemy::Render() {

}

void Enemy::DebugRender() {
	// Render each bullet of spiral's hitbox
	for (auto& bullet : spiral.bullets) {
		bullet.DebugRender();
	}

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