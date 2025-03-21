#include "Silicon.hpp"

#include <Windows.h>

LRESULT CALLBACK WindowProcess(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	case WM_CLOSE:
		DestroyWindow(hwnd);
		return 0;
	case WM_DESTROY:
		if (hwnd == Silicon::getMainWindow()) 
		{
			PostQuitMessage(0);
		}
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

Silicon::Window::Window(const char* name, int2 resolution)
{
	WNDCLASS wc = { };

	wc.lpfnWndProc = WindowProcess;
	wc.hInstance = (HINSTANCE)Silicon::getHInstance();
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