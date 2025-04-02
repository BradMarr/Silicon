#pragma once

#include "Silicon.hpp"
#include "Window.hpp"

#include <d3d11.h>

namespace Silicon
{
    class Renderer
    {
    public:
        Renderer(Window& window);
        ~Renderer();
        void render();
    private:
        IDXGISwapChain* swapChain_;
        ID3D11Device* device_;
        ID3D11DeviceContext* deviceContext_;
        ID3D11RenderTargetView* renderTargetView_;
    };
}