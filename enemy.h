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
	float angleIncrement{ 50.0f };
	float angleIncrementOffset{ 1.0f };

	Enemy(Vector2 position,
		  Vector2 hitboxSize,
		  float maxSpeed,
		  float health,
		  float damage
	);

	// Attack sequences
	void TestAttack_1(float deltaTime);

	void Update(float deltaTime) override;
	void Render() override;

	void DebugRender();
};

#endif