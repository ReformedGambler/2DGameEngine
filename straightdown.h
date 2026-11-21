#ifndef GAMEENGINE_STRAIGHTDOWN_H
#define GAMEENGINE_STRAIGHTDOWN_H

#include "bulletpatterns.h"

class StraightDown : public BulletPatterns {
public:
	void Update(
		float deltaTime,
		std::vector<Bullet>& bullets
	);
};

#endif