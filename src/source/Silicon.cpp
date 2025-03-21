#include "Silicon.hpp"

#include <windows.h>

const void* Silicon::hInstance_ = nullptr;
const void* Silicon::mainWindow_ = nullptr;
const char* Silicon::gameName_ = nullptr;
Silicon::int2 Silicon::gameResolution_ = { NULL, NULL };

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
	gameResolution_ = resolution;
}

const char* const Silicon::getGameName()
{
	return gameName_;
}

Silicon::int2 const Silicon::getGameResolution()
{
	return gameResolution_;
}

const void* const Silicon::getHInstance()
{
	return Silicon::hInstance_;
}

const void* const Silicon::getMainWindow()
{
	return Silicon::mainWindow_;
}