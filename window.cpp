#include "window.h"

// WndProc
LRESULT CALLBACK WndProc(
    _In_    HWND hwnd,
    _In_    UINT msg,
    _In_    WPARAM wParam,
    _In_    LPARAM lParam) {

    switch (msg) {
    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE) {
            PostQuitMessage(0);
        }
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// ProcessMessages
bool ProcessMessages() {
    MSG msg;
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
        {
            //MessageBoxW(nullptr, L"WM_QUIT", L"Debug", MB_OK);
            return false;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return true;
}

// Initialize Window
HWND InitWindow(HINSTANCE hInst, int cmdShow)
{
    WNDCLASSEXW wc{};

    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.hInstance = hInst;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = L"GameWindow";
    wc.hbrBackground = nullptr;

    RegisterClassExW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        L"GameWindow",
        L"",
        WS_POPUP,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        GetSystemMetrics(SM_CXSCREEN),
        GetSystemMetrics(SM_CYSCREEN),
        nullptr,
        nullptr,
        hInst,
        nullptr
    );

    if (!hwnd) {
        //MessageBoxW(nullptr, L"CreateWindowExW failed!", L"Error", MB_OK);
        return false;
    }
    
    ShowWindow(hwnd, cmdShow);
    UpdateWindow(hwnd);

    return hwnd;
}