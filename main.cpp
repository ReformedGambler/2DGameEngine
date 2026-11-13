#include "window.h"
#include "update.h"
#include "renderer.h"
#include "player.h"

int WINAPI WinMain(
	_In_		HINSTANCE hInst,
	_In_opt_	HINSTANCE hPrevInst,
	_In_		LPSTR cmdline,
	_In_		int cmdshow) {
		HWND hwnd = InitWindow(hInst, cmdshow);
		InitDirect2D(hwnd);
		InitTimer();
		Player player;

		while (ProcessMessages()) {
			Update(player);
			Render(player);
		}

		//Shutdown();
	return 0;
}