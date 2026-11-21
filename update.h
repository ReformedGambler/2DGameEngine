#ifndef GAMEENGINE_UPDATE_H
#define GAMEENGINE_UPDATE_H

#include <Windows.h>
#include <cmath>

class Player;
class Enemy;

inline float deltaTime{};

// 1280x720 is the base measurements
// Scaling factor multiplies it automatically

void InitTimer();
void UpdateTimer();
//void BulletMovement();
//bool AABBCheck();
void Update(
	Player& player,
	Enemy& enemy
);

#endif