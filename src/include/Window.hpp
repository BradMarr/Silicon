#pragma once

#include "Silicon.hpp"

#include <Windows.h>

namespace Silicon
{
    class Window
    {
    public:
        Window(const char* name, int2 resolution);
        ~Window();
        int2 resolution_;
        HWND windowHandle_;
    };
}