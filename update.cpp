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

void Update(double deltaTime) {
	float moveX{};
	float moveY{};
	float length{};

	UpdateTimer();

	if (GetAsyncKeyState('W')) {
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
	playerX += moveX * movementSpeed * deltaTime;
	playerY += moveY * movementSpeed * deltaTime;
}