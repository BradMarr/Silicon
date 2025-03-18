#include "Silicon.hpp"

#include <Windows.h>

namespace Silicon 
{
	void error(const char* message) 
    {
		MessageBox(nullptr, message, "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	Silicon::Window window("Silicon", 800, 600, hInstance);

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