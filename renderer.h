#ifndef GAMEENGINE_RENDERER_H
#define GAMEENGINE_RENDERER_H

#include <d2d1.h>
#include "update.h"

class Player;

extern ID2D1Factory* factory;
extern ID2D1HwndRenderTarget* renderTarget;
extern ID2D1SolidColorBrush* brush;

float CalculateScalingFactor();
HRESULT D2D1CreateFactory();
bool InitDirect2D(HWND hwnd);
void Render(Player& player);

#endif