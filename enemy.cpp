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

void Enemy::SpawnBullet(
	int bulletAmount,
	float speed,
	float hitboxSizeX,
	float hitboxSizeY) {
	for (int i = 0; i < bulletAmount; i++) {
		Vector2 centre(
			(position.x + hitboxSize.x / 2.0f) - (hitboxSizeX / 2.0f),
			position.y + hitboxSize.y / 2.0f
		);

		bullets.emplace_back(
			centre,
			Vector2(
				hitboxSizeX,
				hitboxSizeY),
			speed,
			0.0f,
			0.0f
		);
	}
}

void Enemy::SpawnBulletRotated(
	int bulletAmount,
	float speed,
	float hitboxSizeX,
	float hitboxSizeY) {
	for (int i = 0; i < bulletAmount; i++) {
		Vector2 centre(
			(position.x + hitboxSize.x / 2.0f) - (hitboxSizeX / 2.0f),
			position.y + hitboxSize.y / 2.0f
		);

		bullets.emplace_back(
			centre,
			Vector2(
				hitboxSizeX,
				hitboxSizeY),
			speed,
			0.0f,
			0.0f
		);

		float radians = currentAngle * (PI / 180.0f);

		bullets.back().velocityX = speed * std::cos(radians);
		bullets.back().velocityY = speed * std::sin(radians);

		angleIncrement += 1.0f;
		currentAngle += angleIncrement;

		if (currentAngle >= 360.0f) {
			currentAngle -= 360.0f;
		}
	}
}

void Enemy::SpawnBulletDelay(
	double deltaTime,
	float seconds,
	int bulletAmount,
	float speed,
	float hitboxSizeX,
	float hitboxSizeY,
	int type) {
	shootTimer += deltaTime;
	if (shootTimer >= seconds) {
		if (type == 1) {
			SpawnBullet(
				bulletAmount,
				speed,
				hitboxSizeX,
				hitboxSizeY
			);
		}
		else if (type == 2) {
			SpawnBulletRotated(
				bulletAmount,
				speed,
				hitboxSizeX,
				hitboxSizeY
			);
		}
		shootTimer = { 0.0f };
	}
}

void Enemy::StraightDown(double deltaTime, Bullet& bullet) {
	bullet.position.y += bullet.speed * deltaTime;
}

void Enemy::Spiral(double deltaTime, Bullet& bullet) {
	bullet.position.x += bullet.velocityX * deltaTime;
	bullet.position.y += bullet.velocityY * deltaTime;
}

void Enemy::Attack_1(double deltaTime) {
	SpawnBulletDelay(deltaTime, 1.0f, 1, 100.0f, 5.0f, 5.0f, 1);
	for (auto& bullet : bullets) {
		StraightDown(deltaTime, bullet);
	}
}

void Enemy::Attack_2(double deltaTime) {
	SpawnBulletDelay(deltaTime, 0.01f, 1, 200.0f, 5.0f, 5.0f, 2);
	for (auto& bullet : bullets) {
		Spiral(deltaTime, bullet);
	}
}

void Enemy::EraseBullet() {
	for (auto it = bullets.begin(); it != bullets.end();) {
		if (it->IsOffScreen()) {
			it = bullets.erase(it);
		}
		else {
			++it;
		}
	}
}

void Enemy::Update(double deltaTime) {
	//Attack_1(deltaTime);
	Attack_2(deltaTime);
	EraseBullet();
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