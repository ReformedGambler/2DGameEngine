#include "straightdown.h"

void StraightDown::Update(
	double deltaTime,
	std::vector<Bullet>& bullets) {
	for (auto& bullet : bullets) {
		bullet.position.y += bullet.speed * deltaTime;
	}
	EraseBullet(bullets);
}