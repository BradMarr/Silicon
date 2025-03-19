#include "Silicon.hpp"

#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Silicon::Window::Window(const char* name, int2 resolution, void* hInstance)
{
	WNDCLASS wc = { };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = (HINSTANCE)hInstance;
	wc.lpszClassName = name;

	RegisterClass(&wc);

	windowHandle_ = CreateWindowEx(
		0,
		name,
		name,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		resolution.x,
		resolution.y,
		nullptr,
		nullptr,
		nullptr,
		nullptr
	);

	if (windowHandle_ == nullptr)
	{
		error("Failed to create window");
		return;
	}

	ShowWindow((HWND)windowHandle_, SW_SHOW);
	UpdateWindow((HWND)windowHandle_);
}

Silicon::Window::~Window() 
{
	DestroyWindow((HWND)windowHandle_);
}