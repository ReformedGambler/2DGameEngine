#include "enemy.h"

Enemy::Enemy(
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
	// Initialize brush to solid red brush
	renderTarget->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::Red),
		&brush
	);
}

void Enemy::TestAttack_1(float deltaTime) {
	straightDown.Continuous(
		deltaTime,
		1.0f,
		straightDown.bullets,
		position,
		hitboxSize,
		Vector2(5.0f, 20.0f),
		1,
		300.0f
	);
	straightDown.Update(deltaTime, straightDown.bullets);
}

void Enemy::TestAttack_2(float deltaTime) {
	spiral.Continuous(
		deltaTime,
		0.005f,
		spiral.bullets,
		position,
		hitboxSize,
		Vector2(5.0f, 5.0f),
		1,
		100.0f,
		10.0f
	);
	spiral.Update(deltaTime, spiral.bullets);
}

void Enemy::Update(float deltaTime) {
	TestAttack_1(deltaTime);
	TestAttack_2(deltaTime);
}

void Enemy::Render() {

}

void Enemy::DebugRender() {
	// Render each bullet of straightDown's hitbox
	for (auto& bullet : straightDown.bullets) {
		bullet.DebugRender();
	}
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