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
		float speed,
		float angleIncrement
	);

	// Overloading
	void Continuous(
		double deltaTime,
		float secondsInterval,
		std::vector<Bullet>& bullets,
		Vector2 enemyPosition,
		Vector2 enemyHitboxSize,
		Vector2 bulletHitboxSize,
		int bulletAmount,
		float speed,
		float angleIncrement
	);

	void Update(
		double deltaTime,
		std::vector<Bullet>& bullets
	);
};

#endif