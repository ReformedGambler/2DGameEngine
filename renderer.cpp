#include <d2d1.h>
#include "renderer.h"

ID2D1Factory* factory = nullptr;
ID2D1HwndRenderTarget* renderTarget = nullptr;
ID2D1SolidColorBrush* brush = nullptr;

bool InitDirect2D(HWND hwnd) {
    HRESULT hr = D2D1CreateFactory(
        D2D1_FACTORY_TYPE_SINGLE_THREADED,
        &factory
    );

    if (FAILED(hr))
        return false;

    RECT rc;
    GetClientRect(hwnd, &rc);

    hr = factory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(
            hwnd,
            D2D1::SizeU(
                rc.right - rc.left,
                rc.bottom - rc.top)),
        &renderTarget);

    return SUCCEEDED(hr);
}

void Render()
{
    renderTarget->BeginDraw();

    // Background
    renderTarget->Clear(
        D2D1::ColorF(D2D1::ColorF::White));

    // Change brush to solid black brush
    renderTarget->CreateSolidColorBrush(
        D2D1::ColorF(D2D1::ColorF::Black),
        &brush
    );

    // Fill rectangle configurations
    D2D1_RECT_F rect = D2D1::RectF(
        500.0f, // Left
        500.0f, // Top
        300.0f, // Right
        200.0f  // Bottom
    );

    // Draw rectangle
    renderTarget->DrawRectangle(
        rect,
        brush,
        1.0f
    );

    renderTarget->EndDraw();
}