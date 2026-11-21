#ifndef GAMEENGINE_SPIRAL_H
#define GAMEENGINE_SPIRAL_H

#include "bulletpatterns.h"

class Spiral : public BulletPatterns {
public:
	// Overloading
	void Once(
		std::vector<Bullet>& bullets,
		Vector2 enemyPosition,
		Vector2 enemyHitboxSize,
		Vector2 bulletHitboxSize,
		int bulletAmount,
		float maxSpeed,
		float angleIncrement
	);

	// Overloading
	void Continuous(
		float deltaTime,
		float secondsInterval,
		std::vector<Bullet>& bullets,
		Vector2 enemyPosition,
		Vector2 enemyHitboxSize,
		Vector2 bulletHitboxSize,
		int bulletAmount,
		float maxSpeed,
		float angleIncrement
	);

	void Update(
		float deltaTime,
		std::vector<Bullet>& bullets
	);
};

#endif