#ifndef GAMEENGINE_PLAYERMOVEMENT_H
#define GAMEENGINE_PLAYERMOVEMENT_H

class Player;

namespace PlayerMovement {
	void KeyboardInput(float deltaTime, Player& player);
};

#endif