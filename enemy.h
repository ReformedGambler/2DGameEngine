#ifndef GAMEENGINE_ENEMY_H
#define GAMEENGINE_ENEMY_H

#include <vector>

#include "entity.h"
#include "bullet.h"

class Enemy : public Entity {
private:
	float shootTimer{};
	std::vector<Bullet> bullets;
	ID2D1SolidColorBrush* brush{};

public:
	Enemy(Vector2 position,
		  Vector2 hitboxSize,
		  float speed,
		  float health,
		  float damage
	);

	void SpawnBullet(
		int bulletAmount,
		float speed,
		float hitboxSizeX,
		float hitboxSizeY
	);
	void SpawnBulletDelay(
		double deltaTime,
		float seconds,
		int bulletAmount,
		float speed,
		float hitboxSizeX,
		float hitboxSizeY
	);
	void StraightDown(
		double deltaTime,
		Bullet& bullet
	);
	void Attack_1(double deltaTime);
	void EraseBullet();

	void Update(double deltaTime) override;
	void Render() override;

	void DebugRender();
};

#endif