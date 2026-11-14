#ifndef GAMEENGINE_ENEMY_H
#define GAMEENGINE_ENEMY_H

#include <vector>

#include "entity.h"
#include "bullet.h"

class Enemy : public Entity {
private:
	float shootTimer{};
	float shootInterval{};

public:
	Enemy(Vector2 position,
		  Vector2 hitboxSize,
		  float speed,
		  float health,
		  float damage
	);

	std::vector<Bullet> bullets;

	// Bullet
	void SpawnBullet();
	void SpawnBulletWithDelay(double deltaTime, float seconds);
	void StraightDown(double deltaTime, Bullet& bullet);

	void Update(double deltaTime) override;
	void Render() override;

	void DebugRender();
};

#endif