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

}

void Enemy::SpawnBullet() {
	float bulletHitboxSizeX{ 5.0f };
	float bulletHitboxSizeY{ 10.0f };

	for (int i = 0; i < 50; i++) {
		Vector2 centre(
			(position.x + hitboxSize.x / 2.0f) - (bulletHitboxSizeX / 2.0f),
			position.y + hitboxSize.y / 2.0f
		);

		bullets.emplace_back(
			centre,
			Vector2(
				bulletHitboxSizeX,
				bulletHitboxSizeY),
			100.0f,
			0.0f,
			0.0f
		);
	}
}

void Enemy::SpawnBulletWithDelay(double deltaTime, float seconds) {
	shootTimer += deltaTime;
	if (shootTimer >= seconds) {
		SpawnBullet();
		shootTimer = { 0.0f };
	}
}

void Enemy::StraightDown(double deltaTime, Bullet& bullet) {
	bullet.position.y += bullet.speed * deltaTime;
}

void Enemy::Update(double deltaTime) {
	SpawnBulletWithDelay(deltaTime, 2.0f);
	for (auto& bullet : bullets) {
		StraightDown(deltaTime, bullet);
	}
}

void Enemy::Render() {

}

void Enemy::DebugRender() {
	for (auto& bullet : bullets) {
		bullet.DebugRender();
	}

	// Change brush to solid black brush
	renderTarget->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::Black),
		&brush
	);

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