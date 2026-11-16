#ifndef GAMEENGINE_STRAIGHTDOWN_H
#define GAMEENGINE_STRAIGHTDOWN_H

#include "bulletpatterns.h"

class StraightDown : public BulletPatterns {
public:
	void Update(
		double deltaTime,
		std::vector<Bullet>& bullets
	);
};

#endif