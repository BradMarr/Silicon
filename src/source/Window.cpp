#include "Silicon.hpp"
#include "Engine.hpp"

using namespace Silicon;

LRESULT CALLBACK WindowProcess(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	case WM_CLOSE:
		DestroyWindow(hwnd);
		return 0;
	case WM_DESTROY:
		if (hwnd == Engine::mainWindow_->windowHandle_) 
		{
			PostQuitMessage(0);
		}
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

Window::Window(const char* name, int2 resolution)
	: resolution_(resolution)
{
	WNDCLASS wc = { };

	wc.lpfnWndProc = WindowProcess;
	wc.hInstance = Engine::hInstance_;
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

	ShowWindow(windowHandle_, SW_SHOW);
	UpdateWindow(windowHandle_);
}

Window::~Window() 
{
	DestroyWindow(windowHandle_);
}