#pragma once

class Silicon
{
public:
    struct int2 {
        int x, y;
    };

    /**
	* @brief User-defined function that runs before main window gets initalized.
    */
    static void config();
    /**
    * @brief User-defined function that runs before the game loop.
    */
    static void init();
    /**
    * @brief User-defined function that runs every draw cycle.
    */
    static void gameLoop();
    /**
	* @brief User-defined function that runs after the game loop.
    */
	static void cleanup();

    static void setGameName(const char* name);
    static void setGameResolution(int2 resolution);

	static const char* const getGameName();
	static int2 const getGameResolution();
    static const void* const getHInstance();
	static const void* const getMainWindow();

    static void error(const char* message);

    class Window
    {
    public:
        Window(const char* name, Silicon::int2 resolution);
        ~Window();
        Silicon::int2 resolution_ = { 0, 0 };
        const void* windowHandle_;
    };

 //   class Renderer
 //   {
	//public:
	//	Renderer(Window window);
	//	~Renderer();
 //   private:
 //       void* swapChain_ = nullptr;
 //       void* device_ = nullptr;
 //       void* deviceContext_ = nullptr;
 //       void* renderTargetView_ = nullptr;
 //   };

private:
	static const void* hInstance_;
    static const void* mainWindow_;
    static const char* gameName_;
	static int2 gameResolution_;

	friend void setHInstance(const void* hInstance);
	friend void setMainWindow(const void* mainWindow);
};