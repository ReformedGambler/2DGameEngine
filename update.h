#ifndef GAMEENGINE_UPDATE_H
#define GAMEENGINE_UPDATE_H

#include <Windows.h>
#include <cmath>

// 1280x720 is the base measurements
// Scaling factor multiplies it automatically
inline float playerX{ 615.0f };
inline float playerY{ 600.0f };
inline float playerWidth{ 20.0f };
inline float playerHeight{ 40.0f };
inline float playerMovementSpeed{ 200.0f };

inline float bulletX{ 622.5f };
inline float bulletY{ 100.0f };
inline float bulletWidth{ 5.0f };
inline float bulletHeight{ 10.0f };
inline float bulletMovementSpeed{ 100.0f };
inline bool bulletActive{ true };

inline double deltaTime{};

void InitTimer();
void UpdateTimer();
void PlayerMovement();
void BulletMovement();
bool AABBCheck();
void Update();

#endif