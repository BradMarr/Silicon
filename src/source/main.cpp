#include "Silicon.hpp"

#include <Windows.h>

void setHInstance(const void* hInstance)
{
	Silicon::hInstance_ = hInstance;
}

void setMainWindow(const void* mainWindow)
{
	Silicon::mainWindow_ = mainWindow;
}

static int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
	setHInstance(hInstance);

    Silicon::config();

    if (Silicon::getGameName() == nullptr)
    {
        Silicon::error("Game name should be declared inside of the config function.");
    }

    if (Silicon::getGameResolution().x == NULL || Silicon::getGameResolution().y == NULL)
    {
        Silicon::error("Game resolution should be declared inside of the config function.");
    }

    Silicon::Window window(Silicon::getGameName(), Silicon::getGameResolution());
	setMainWindow(window.windowHandle_);

	Silicon::init();

    MSG msg = {};
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Silicon::gameLoop();
        }
    }

    Silicon::cleanup();

    return 0;
}