#include "update.h"

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

void PlayerMovement() {
	float moveX{};
	float moveY{};
	float length{};

	UpdateTimer();

	if (GetAsyncKeyState('W')) {
		//VK_SPACE
		moveY -= 1.0f;
	}
	if (GetAsyncKeyState('A')) {
		moveX -= 1.0f;
	}
	if (GetAsyncKeyState('S')) {
		moveY += 1.0f;
	}
	if (GetAsyncKeyState('D')) {
		moveX += 1.0f;
	}

	length = sqrtf(moveX * moveX + moveY * moveY);
	if (length > 0.0f) {
		moveX /= length;
		moveY /= length;
	}

	playerX += moveX * playerMovementSpeed * deltaTime;
	playerY += moveY * playerMovementSpeed * deltaTime;
}

void BulletMovement() {
	bulletY += bulletMovementSpeed * deltaTime;
}

bool AABBCheck() {
	float playerMinX{ playerX };
	float playerMaxX{ playerX + playerWidth };
	float playerMinY{ playerY };
	float playerMaxY{ playerY + playerHeight };

	float bulletMinX{ bulletX };
	float bulletMaxX{ bulletX + bulletWidth };
	float bulletMinY{ bulletY };
	float bulletMaxY{ bulletY + bulletHeight };

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
}

void Update() {
	PlayerMovement();
	BulletMovement();
	if (AABBCheck()) {
		playerActive = false;
		bulletActive = false;
	}
}