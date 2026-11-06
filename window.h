#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H

#include <Windows.h>

LRESULT CALLBACK WndProc(
    _In_    HWND hwnd,
    _In_    UINT msg,
    _In_    WPARAM wParam,
    _In_    LPARAM lParam);

bool InitWindow(HINSTANCE hInst, int cmdShow);

#endif