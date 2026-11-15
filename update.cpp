#include "update.h"
#include "player.h"
#include "enemy.h"

LARGE_INTEGER counter{};
LARGE_INTEGER frequency{};
double currentCounter{};
double previousCounter{};

void InitTimer() {
	QueryPerformanceCounter(&counter);
	QueryPerformanceFrequency(&frequency);

	previousCounter = static_cast<double>(counter.QuadPart);
}

void UpdateTimer() {
	QueryPerformanceCounter(&counter);

	currentCounter = static_cast<double>(counter.QuadPart);
	deltaTime = (currentCounter - previousCounter) /
				static_cast<double>(frequency.QuadPart);
	previousCounter = currentCounter;
}

/*
bool AABBCheck(float playerMinX,
			   float playerMaxX,
			   float playerMinY,
			   float playerMaxY,
			   float bulletMinX,
			   float bulletMaxX,
			   float bulletMinY,
			   float bulletMaxY) {
	float overlapX{
		std::fmin(playerMaxX, bulletMaxX) -
		std::fmax(playerMinX, bulletMinX)
	};

	float overlapY{
		std::fmin(playerMaxY, bulletMaxY) -
		std::fmax(playerMinY, bulletMinY)
	};

	if (overlapX > 0 && overlapY > 0) {
		return true;
	}

	return false;
} */

void Update(
	Player& player,
	Enemy& enemy) {
	UpdateTimer();
	player.Update(deltaTime);
	enemy.Update(deltaTime);

	/*
	if (AABBCheck(
		playerX,
		(playerX + playerWidth),
		playerY,
		(playerY + playerHeight),
		bulletX,
		(bulletX + bulletWidth),
		bulletY,
		(bulletY + bulletHeight))) {
		bulletActive = false;
	}
	if (AABBCheck(
		playerX,
		(playerX + playerWidth),
		playerY,
		(playerY + playerHeight),
		bullet2X,
		(bullet2X + bullet2Width),
		bullet2Y,
		(bullet2Y + bullet2Height))) {
		bullet2Active = false;
	}
	*/
}