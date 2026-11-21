#include "spiral.h"

// Overloading
void Spiral::Once(
	std::vector<Bullet>& bullets,
	Vector2 enemyPosition,
	Vector2 enemyHitboxSize,
	Vector2 bulletHitboxSize,
	int bulletAmount,
	float maxSpeed,
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
			maxSpeed,
			0.0f
		);

		radians = currentAngle * (PI / 180.0f);

		bullets.back().velocityX = maxSpeed * std::cos(radians);
		bullets.back().velocityY = maxSpeed * std::sin(radians);

		currentAngle += angleIncrement;

		if (currentAngle >= 360.0f) {
			currentAngle -= 360.0f;
		}
	}
}

// Overloading
void Spiral::Continuous(
	float deltaTime,
	float secondsInterval,
	std::vector<Bullet>& bullets,
	Vector2 enemyPosition,
	Vector2 enemyHitboxSize,
	Vector2 bulletHitboxSize,
	int bulletAmount,
	float maxSpeed,
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
			maxSpeed,
			angleIncrement
		);
		shootTimer = { 0.0f };
	}
}

void Spiral::Update(
	float deltaTime,
	std::vector<Bullet>& bullets) {
	for (auto& bullet : bullets) {
		bullet.position.x += bullet.velocityX * deltaTime;
		bullet.position.y += bullet.velocityY * deltaTime;
	}
	EraseBullet(bullets);
}