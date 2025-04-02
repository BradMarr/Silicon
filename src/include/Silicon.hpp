#pragma once

namespace Silicon
{
    struct int2 
    {
        int x, y;
    };

    struct float3 
    {
        float x, y, z;
    };

    /**
	* @brief User-defined function that runs before main window gets initalized.
    */
    void config();
    /**
    * @brief User-defined function that runs before the game loop.
    */
    void init();
    /**
    * @brief User-defined function that runs every draw cycle.
    */
    void gameLoop();
    /**
	* @brief User-defined function that runs after the game loop.
    */
	void cleanup();

    void setGameName(const char* name);
	void setGameResolution(int2 resolution);

	const char* getGameName();
	int2 getGameResolution();

    void error(const char* message);
};