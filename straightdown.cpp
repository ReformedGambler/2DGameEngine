#include "straightdown.h"

void StraightDown::Update(
	float deltaTime,
	std::vector<Bullet>& bullets,
	float secondsInterval) {
	for (auto& bullet : bullets) {
		bullet.position.y += bullet.maxSpeed * deltaTime;
	}
	EraseBullet(bullets, secondsInterval, deltaTime);
}