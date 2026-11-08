#include "renderer.h"

ID2D1Factory* factory{ nullptr };
ID2D1HwndRenderTarget* renderTarget{ nullptr };
ID2D1SolidColorBrush* brush{ nullptr };

int SCREEN_WIDTH{ GetSystemMetrics(SM_CXSCREEN) };
int SCREEN_HEIGHT{ GetSystemMetrics(SM_CYSCREEN) };
float scalingFactorX{ (SCREEN_WIDTH / 1280.0f) };
float scalingFactorY{ (SCREEN_HEIGHT / 720.0f) };
float scalingFactor{ CalculateScalingFactor() };

float CalculateScalingFactor() {
    if (scalingFactorX < scalingFactorY) {
        return scalingFactorX;
    }
    else {
        return scalingFactorY;
    }
}

bool InitDirect2D(HWND hwnd) {
    HRESULT hr{ D2D1CreateFactory(
        D2D1_FACTORY_TYPE_SINGLE_THREADED,
        &factory
    )};

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

    renderTarget->SetTransform(
        D2D1::Matrix3x2F::Scale(
            scalingFactor,
            scalingFactor
        )
    );

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
        playerX,
        playerY,
        playerX + playerWidth,
        playerY + playerHeight
    );

    // Draw rectangle
    renderTarget->DrawRectangle(
        rect,
        brush,
        1.0f
    );

    renderTarget->EndDraw();
}