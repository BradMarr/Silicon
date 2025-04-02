#include "Silicon.hpp"
#include "Engine.hpp"
#include "Renderer.hpp"

using namespace Silicon;

static int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
    Engine::hInstance_ = hInstance;

    config();

    if (getGameName() == nullptr)
    {
        error("Game name should be declared inside of the config function.");
    }

    if (getGameResolution().x == NULL || getGameResolution().y == NULL)
    {
        error("Game resolution should be declared inside of the config function.");
    }

    Window window(getGameName(), getGameResolution());
	Engine::mainWindow_ = &window;

    Renderer renderer(window);

	init();

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
            gameLoop();
			renderer.render();
        }
    }

    cleanup();

    return 0;
}