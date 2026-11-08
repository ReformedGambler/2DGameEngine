#ifndef GAMEENGINE_WINDOW_H
#define GAMEENGINE_WINDOW_H

#include <Windows.h>
#include "renderer.h"

// Initialize WndProc
LRESULT CALLBACK WndProc(
    _In_    HWND hwnd,
    _In_    UINT msg,
    _In_    WPARAM wParam,
    _In_    LPARAM lParam);

// Initialize Message Loop
bool ProcessMessages();

// Initialize Window
HWND InitWindow(HINSTANCE hInst, int cmdShow);

#endif