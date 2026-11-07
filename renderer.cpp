#include <d2d1.h>
#include "renderer.h"

ID2D1Factory* g_pFactory = nullptr;
ID2D1HwndRenderTarget* g_pRenderTarget = nullptr;

bool InitDirect2D(HWND hwnd) {
    HRESULT hr = D2D1CreateFactory(
        D2D1_FACTORY_TYPE_SINGLE_THREADED,
        &g_pFactory
    );

    if (FAILED(hr))
        return false;

    RECT rc;
    GetClientRect(hwnd, &rc);

    hr = g_pFactory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(
            hwnd,
            D2D1::SizeU(
                rc.right - rc.left,
                rc.bottom - rc.top)),
        &g_pRenderTarget);

    return SUCCEEDED(hr);
}

void Render()
{
    OutputDebugStringW(L"Render called\n");

    g_pRenderTarget->BeginDraw();
    g_pRenderTarget->Clear(
        D2D1::ColorF(D2D1::ColorF::Violet));
    g_pRenderTarget->EndDraw();
}