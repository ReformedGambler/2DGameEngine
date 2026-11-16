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

/*
float radians = currentAngle * (PI / 180.0f);

bullets.back().velocityX = speed * std::cos(radians);
bullets.back().velocityY = speed * std::sin(radians);

angleIncrement += 1.0f;
currentAngle += angleIncrement;

if (currentAngle >= 360.0f) {
	currentAngle -= 360.0f;
}
*/
/*
bullet.position.x += bullet.velocityX * deltaTime;
bullet.position.y += bullet.velocityY * deltaTime;
*/

void Enemy::TestAttack(double deltaTime) {
	straightDown.SetSpawnOffset(Vector2(0.0f, 0.0f));
	straightDown.Cont(
		deltaTime,
		1.0f,
		bullets,
		position,
		hitboxSize,
		1,
		100.0f,
		5.0f,
		5.0f
	);
}

void Enemy::Update(double deltaTime) {
	TestAttack(deltaTime);
	straightDown.Update(deltaTime, bullets);
}

void Enemy::Render() {

}

void Enemy::DebugRender() {
	// Render each bullet's hitbox
	for (auto& bullet : bullets) {
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