#pragma once

namespace Silicon 
{
    /**
    * @brief User-defined function that runs every draw cycle.
    */
    void gameLoop();
    /**
    * @brief User-defined function that runs before game loop.
    */
    void init(char* name);

	void error(const char* message);

    class Window 
    {
    public:
        Window(const char* name, int width, int height, void* hInstance);
        ~Window();
    private:
		void* windowHandle_;
    };
}