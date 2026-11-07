#include <Windows.h>

#include "window.h"
#include "renderer.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInst,
	_In_opt_ HINSTANCE hPrevInst,
	_In_ LPSTR cmdline,
	_In_ int cmdshow) {
		HWND hwnd = InitWindow(hInst, cmdshow);
		InitDirect2D(hwnd);

		while (ProcessMessages()) {
			//Update();
			Render();
		}

		//Shutdown();
	return 0;
}