#pragma once

class Silicon
{
public:
    struct int2 {
        int2(int x, int y) : x(x), y(y) {}
        int x, y;
    };

    /**
    * @brief User-defined function that runs every draw cycle.
    */
    static void gameLoop();
    /**
    * @brief User-defined function that runs before game loop.
    * @param name The name of the window.
    */
    static void init();

    static void setGameName(const char* name);
    static void setGameResolution(int2 resolution);

	static const char* getGameName();
	static int2 getGameResolution();

    static void error(const char* message);

    class Window
    {
    public:
        Window(const char* name, Silicon::int2 resolution, void* hInstance);
        ~Window();
        const void* windowHandle_;
    };

private:
    static const char* gameName_;
	static int2 windowSize_;
};