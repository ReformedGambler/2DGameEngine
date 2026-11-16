#ifndef GAMEENGINE_ENEMY_H
#define GAMEENGINE_ENEMY_H

#include <vector>
#include <cmath>

#include "entity.h"
#include "bullet.h"
#include "straightdown.h"

class Enemy : public Entity {
private:
	std::vector<Bullet> bullets;
	ID2D1SolidColorBrush* brush{};

	// BulletPatterns
	StraightDown straightDown;

public:
	Enemy(Vector2 position,
		  Vector2 hitboxSize,
		  float speed,
		  float health,
		  float damage
	);

	void TestAttack(double deltaTime);

	void Update(double deltaTime) override;
	void Render() override;

	void DebugRender();
};

#endif