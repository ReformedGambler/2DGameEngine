#ifndef GAMEENGINE_UPDATE_H
#define GAMEENGINE_UPDATE_H

#include <Windows.h>
#include <cmath>

class Player;

// 1280x720 is the base measurements
// Scaling factor multiplies it automatically
inline float bulletX{ 622.5f };
inline float bulletY{ 100.0f };
inline float bulletWidth{ 5.0f };
inline float bulletHeight{ 10.0f };
inline float bulletMovementSpeed{ 100.0f };
inline bool bulletActive{ true };

inline float bullet2X{ 625.0f };
inline float bullet2Y{ 100.0f };
inline float bullet2Width{ 5.0f };
inline float bullet2Height{ 10.0f };
inline float bullet2MovementSpeed{ 100.0f };
inline bool bullet2Active{ true };

inline double deltaTime{};

void InitTimer();
void UpdateTimer();
//void BulletMovement();
//bool AABBCheck();
void Update(Player& player);

#endif