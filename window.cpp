#include <Windows.h>

LRESULT CALLBACK WndProc(
    _In_    HWND hwnd,
    _In_    UINT msg,
    _In_    WPARAM wParam,
    _In_    LPARAM lParam) {
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

bool InitWindow(HINSTANCE hInst, int cmdShow)
{
    WNDCLASSEXW wc{};

    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.hInstance = hInst;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = L"GameWindow";

    RegisterClassExW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        L"GameWindow",
        L"2D Game Engine",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        1280,
        720,
        nullptr,
        nullptr,
        hInst,
        nullptr
    );

    if (!hwnd)
        return false;

    ShowWindow(hwnd, cmdShow);

    return true;
}