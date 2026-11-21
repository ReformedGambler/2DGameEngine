#include "spiral.h"

// Overloading
void Spiral::Once(
	std::vector<Bullet>& bullets,
	Vector2 enemyPosition,
	Vector2 enemyHitboxSize,
	Vector2 bulletHitboxSize,
	int bulletAmount,
	float speed,
	float angleIncrement) {
	for (int i = 0; i < bulletAmount; i++) {
		Vector2 spawn(
			enemyPosition.x + enemyHitboxSize.x / 2.0f
			+ spawnOffset.x - bulletHitboxSize.x / 2.0f,

			enemyPosition.y + enemyHitboxSize.y / 2.0f
			+ spawnOffset.y
		);

		bullets.emplace_back(
			spawn,
			Vector2(
				bulletHitboxSize.x,
				bulletHitboxSize.y),
			speed,
			0.0f
		);

		radians = currentAngle * (PI / 180.0f);

		bullets.back().velocityX = speed * std::cos(radians);
		bullets.back().velocityY = speed * std::sin(radians);

		currentAngle += angleIncrement;

		if (currentAngle >= 360.0f) {
			currentAngle -= 360.0f;
		}
	}
}

// Overloading
void Spiral::Continuous(
	double deltaTime,
	float secondsInterval,
	std::vector<Bullet>& bullets,
	Vector2 enemyPosition,
	Vector2 enemyHitboxSize,
	Vector2 bulletHitboxSize,
	int bulletAmount,
	float speed,
	float angleIncrement) {
	shootTimer += deltaTime;
	if (shootTimer >= secondsInterval) {
		Once(
			bullets,
			Vector2(
				enemyPosition.x,
				enemyPosition.y
			),
			Vector2(
				enemyHitboxSize.x,
				enemyHitboxSize.y
			),
			Vector2(
				bulletHitboxSize.x,
				bulletHitboxSize.y
			),
			bulletAmount,
			speed,
			angleIncrement
		);
		shootTimer = { 0.0f };
	}
}

void Spiral::Update(
	double deltaTime,
	std::vector<Bullet>& bullets) {
	for (auto& bullet : bullets) {
		bullet.position.x += bullet.velocityX * deltaTime;
		bullet.position.y += bullet.velocityY * deltaTime;
	}
	EraseBullet(bullets);
}