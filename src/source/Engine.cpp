#include "Engine.hpp"

using namespace Silicon;

HINSTANCE Engine::hInstance_ = nullptr;
const Window* Engine::mainWindow_ = nullptr;
const char* Engine::gameName_ = nullptr;
int2 Engine::gameResolution_ = { 0, 0 };