#ifndef GAMEENGINE_RENDERER_H
#define GAMEENGINE_RENDERER_H

#include <d2d1.h>

extern ID2D1Factory* factory;
extern ID2D1HwndRenderTarget* renderTarget;
extern ID2D1SolidColorBrush* brush;

HRESULT D2D1CreateFactory();

// Initialize Direct2D
bool InitDirect2D(HWND hwnd);

// Render
void Render();

#endif