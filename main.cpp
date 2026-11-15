#include "window.h"
#include "update.h"
#include "renderer.h"
#include "player.h"
#include "enemy.h"

int WINAPI WinMain(
	_In_		HINSTANCE hInst,
	_In_opt_	HINSTANCE hPrevInst,
	_In_		LPSTR cmdline,
	_In_		int cmdshow) {
		HWND hwnd = InitWindow(hInst, cmdshow);
		InitDirect2D(hwnd);
		InitTimer();
		Player player(
			Vector2(615.0f, 600.0f),
			Vector2(20, 40),
			200.0f,
			100.0f,
			1.0f
		);
		Enemy enemy(
			Vector2(605.0f, 300.0f),
			Vector2(40.0f, 40.0f),
			200.0f,
			100.0f,
			1.0f
		);

		while (ProcessMessages()) {
			Update(player, enemy);
			Render(player, enemy);
		}

		//Shutdown();
	return 0;
}