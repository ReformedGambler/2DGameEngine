#ifndef GAMEENGINE_ENEMY_H
#define GAMEENGINE_ENEMY_H

#include <vector>
#include <cmath>

#include "entity.h"

// BulletPatterns
#include "straightdown.h"
#include "spiral.h"

class Enemy : public Entity {
private:
	ID2D1SolidColorBrush* brush{};

	// BulletPatterns
	StraightDown straightDown;
	Spiral spiral;

public:
	Enemy(Vector2 position,
		  Vector2 hitboxSize,
		  float speed,
		  float health,
		  float damage
	);

	// Attack sequences
	void TestAttack_1(double deltaTime);
	void TestAttack_2(double deltaTime);

	void Update(double deltaTime) override;
	void Render() override;

	void DebugRender();
};

#endif