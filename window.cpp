#include <Windows.h>

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

    case WM_PAINT:
        // Code here
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// ProcessMessages
bool ProcessMessages() {
    BOOL bRet;
    MSG msg;
    while ((bRet = GetMessage(&msg, nullptr, 0, 0)) != 0)
    {
        if (bRet == -1)
        {
            // handle the error and possibly exit
            return 0;
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}

// Initialize Window
bool InitWindow(HINSTANCE hInst, int cmdShow)
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
        MessageBoxW(nullptr, L"CreateWindowExW failed!", L"Error", MB_OK);
        return false;
    }
    
    ShowWindow(hwnd, cmdShow);
    UpdateWindow(hwnd);

    return true;
}