#include "bulletpatterns.h"

void BulletPatterns::SetSpawnOffset(Vector2 offset) {
	spawnOffset = offset;
}

void BulletPatterns::Once(
	std::vector<Bullet>& bullets,
	Vector2 position,
	Vector2 hitboxSize,
	int bulletAmount,
	float speed,
	float hitboxSizeX,
	float hitboxSizeY) {
	for (int i = 0; i < bulletAmount; i++) {
		Vector2 spawn(
			position.x + hitboxSize.x / 2.0f
			- hitboxSizeX / 2.0f + spawnOffset.x,

			position.y + hitboxSize.y / 2.0f
			- hitboxSizeY / 2.0f + spawnOffset.y
		);

		bullets.emplace_back(
			spawn,
			Vector2(
				hitboxSizeX,
				hitboxSizeY),
			speed,
			0.0f,
			0.0f
		);
	}
}

void BulletPatterns::Cont(
	double deltaTime,
	float secondsInterval,
	std::vector<Bullet>& bullets,
	Vector2 position,
	Vector2 hitboxSize,
	int bulletAmount,
	float speed,
	float hitboxSizeX,
	float hitboxSizeY) {
	shootTimer += deltaTime;
	if (shootTimer >= secondsInterval) {
		Once(
			bullets,
			position,
			hitboxSize,
			bulletAmount,
			speed,
			hitboxSizeX,
			hitboxSizeY
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