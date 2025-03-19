#pragma once

namespace Silicon 
{
	void error(const char* message);

    void gameLoop();
    void init();

    class Window 
    {
    public:
        Window(const char* name, int width, int height, void* hInstance);
        ~Window();
    private:
		void* windowHandle_;
    };
}