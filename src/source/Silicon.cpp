#include "Silicon.hpp"
#include "Engine.hpp"

using namespace Silicon;

void Silicon::error(const char* message) 
{
	MessageBox(nullptr, message, "Error", MB_OK | MB_ICONERROR);
	exit(1);
}

void Silicon::setGameName(const char* name)
{
	if (Engine::gameName_ != nullptr)
	{
		error("Game name should be declared only once.");
	}
	Engine::gameName_ = name;
}

void Silicon::setGameResolution(int2 resolution)
{
	Engine::gameResolution_ = resolution;
}

const char* Silicon::getGameName()
{
	return Engine::gameName_;
}

int2 Silicon::getGameResolution()
{
	return Engine::gameResolution_;
}