#include "update.h"

void Update() {
	if (GetAsyncKeyState('W')) {
		playerY -= movementSpeed;
	}
	else if (GetAsyncKeyState('A')) {
		playerX -= movementSpeed;
	}
	else if (GetAsyncKeyState('S')) {
		playerY += movementSpeed;
	}
	else if (GetAsyncKeyState('D')) {
		playerX += movementSpeed;
	}
}