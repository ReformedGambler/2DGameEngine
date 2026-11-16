#ifndef GAMEENGINE_BULLETPATTERNS_H
#define GAMEENGINE_BULLETPATTERNS_H

#include <vector>

#include "bullet.h"

class BulletPatterns {
private:
	Vector2 spawnOffset{ 0.0f, 0.0f };	// Spawnpoint of each bullet (default is centred)
	const float PI{ 3.1416f };
	float shootTimer{};					// Controls firing intervals
	float currentAngle{};				// Tracks current spiral rotation
	float angleIncrement{};				// Controls how much the angle changes per shot

public:
	void SetSpawnOffset(Vector2 offset);

	void Once(
		std::vector<Bullet>& bullets,
		Vector2 position,		// Enemy
		Vector2 hitboxSize,		// Enemy
		int bulletAmount,		// Bullet
		float speed,			// Bullet
		float hitboxSizeX,		// Bullet
		float hitboxSizeY		// Bullet
	);

	void Cont(
		double deltaTime,
		float secondsInterval,
		std::vector<Bullet>& bullets,
		Vector2 position,		// Enemy
		Vector2 hitboxSize,		// Enemy
		int bulletAmount,		// Bullet
		float speed,			// Bullet
		float hitboxSizeX,		// Bullet
		float hitboxSizeY		// Bullet
	);

	void EraseBullet(
		std::vector<Bullet>& bullets
	);
};

#endif