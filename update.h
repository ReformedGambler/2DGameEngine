#ifndef GAMEENGINE_UPDATE_H
#define GAMEENGINE_UPDATE_H

#include <Windows.h>
#include <cmath>

// 1280x720 is the base measurements
// Scaling factor multiplies it automatically
inline float playerX{ 615.0f };
inline float playerY{ 600.0f };
inline float playerWidth{ 50.0f };
inline float playerHeight{ 50.0f };
inline float movementSpeed{ 200.0f };
inline double deltaTime{};

void InitTimer();
void UpdateTimer();
void Update(double deltaTime);

#endif