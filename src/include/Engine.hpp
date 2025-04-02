#pragma once

#include "Window.hpp"

#include <Windows.h>

namespace Silicon 
{
    namespace Engine 
    {
        extern HINSTANCE hInstance_;
        extern const Window* mainWindow_;
        extern const char* gameName_;
        extern struct int2 gameResolution_;
    };
}