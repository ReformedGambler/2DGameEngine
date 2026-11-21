#include "bulletpatterns.h"

void BulletPatterns::SetSpawnOffset(Vector2 offset) {
	spawnOffset = offset;
}

void BulletPatterns::Once(
	std::vector<Bullet>& bullets,
	Vector2 enemyPosition,
	Vector2 enemyHitboxSize,
	Vector2 bulletHitboxSize,
	int bulletAmount,
	float speed) {
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
	}
}

void BulletPatterns::Continuous(
	float deltaTime,
	float secondsInterval,
	std::vector<Bullet>& bullets,
	Vector2 enemyPosition,
	Vector2 enemyHitboxSize,
	Vector2 bulletHitboxSize,
	int bulletAmount,
	float speed) {
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
			speed
		);
		shootTimer = { 0.0f };
	}
}

void BulletPatterns::EraseBullet(
	std::vector<Bullet>& bullets) {
	for (auto it = bullets.begin(); it != bullets.end();) {
		if (it->IsOffScreen()) {
			it = bullets.erase(it);
		}
		else {
			++it;
		}
	}
}