#include "window.h"
#include "update.h"
#include "renderer.h"

int WINAPI WinMain(
	_In_		HINSTANCE hInst,
	_In_opt_	HINSTANCE hPrevInst,
	_In_		LPSTR cmdline,
	_In_		int cmdshow) {
		HWND hwnd = InitWindow(hInst, cmdshow);
		InitDirect2D(hwnd);
		InitTimer();

		while (ProcessMessages()) {
			Update(deltaTime);
			Render();
		}

		//Shutdown();
	return 0;
}