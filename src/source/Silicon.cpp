#include "Silicon.hpp"

#include <windows.h>

namespace Silicon 
{
	void error(const char* message) 
    {
		MessageBox(nullptr, message, "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
    char* name;

    Silicon::init(name);
    
	Silicon::Window window(name, 800, 600, hInstance);

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