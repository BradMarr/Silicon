#include "Silicon.hpp"

#include <windows.h>

const char* Silicon::gameName_ = nullptr;
Silicon::int2 Silicon::windowSize_ = { NULL, NULL };

void Silicon::error(const char* message) 
{
	MessageBox(nullptr, message, "Error", MB_OK | MB_ICONERROR);
	exit(1);
}

void Silicon::setGameName(const char* name)
{
	if (gameName_ != nullptr)
	{
		Silicon::error("Game name should be declared only once.");
	}
	gameName_ = name;
}

void Silicon::setGameResolution(int2 resolution)
{
	if (Silicon::getGameResolution().x != NULL || Silicon::getGameResolution().y != NULL)
	{
		Silicon::error("Game resolution should be declared only once.");
	}
	windowSize_ = resolution;
}

const char* Silicon::getGameName()
{
	return gameName_;
}

Silicon::int2 Silicon::getGameResolution()
{
	return windowSize_;
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
    Silicon::init();

	if (Silicon::getGameName() == nullptr)
	{
		Silicon::error("Game name should be declared inside of the init function.");
	}

	if (Silicon::getGameResolution().x == NULL || Silicon::getGameResolution().y == NULL)
	{
		Silicon::error("Game resolution should be declared inside of the init function.");
	}
    
	Silicon::Window window(Silicon::getGameName(), Silicon::getGameResolution(), hInstance);

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

	return 0;
}