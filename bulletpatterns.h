#ifndef GAMEENGINE_BULLETPATTERNS_H
#define GAMEENGINE_BULLETPATTERNS_H

#include <vector>

#include "bullet.h"

class BulletPatterns {
public:
	Vector2 spawnOffset{ 0.0f, 0.0f };	// Spawnpoint of each bullet (default is centred)
	const float PI{ 3.1416f };
	float radians{};
	float shootTimer{};					// Controls firing intervals
	float currentAngle{};				// Tracks current spiral rotation
	float angleIncrement{};				// Controls how much the angle changes per shot

	std::vector<Bullet> bullets;

	void SetSpawnOffset(Vector2 offset);

	void Once(
		std::vector<Bullet>& bullets,
		Vector2 enemyPosition,
		Vector2 enemyHitboxSize,
		Vector2 bulletHitboxSize,
		int bulletAmount,
		float speed
	);

	void Continuous(
		float deltaTime,
		float secondsInterval,
		std::vector<Bullet>& bullets,
		Vector2 enemyPosition,
		Vector2 enemyHitboxSize,
		Vector2 bulletHitboxSize,
		int bulletAmount,
		float speed
	);

	void EraseBullet(
		std::vector<Bullet>& bullets
	);
};

#endif