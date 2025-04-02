#include "Silicon.hpp"
#include "Renderer.hpp"

using namespace Silicon;

Renderer::Renderer(Window& window) 
{
    DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
    swapChainDesc.BufferCount = 1;
    swapChainDesc.BufferDesc.Width = window.resolution_.x;
    swapChainDesc.BufferDesc.Height = window.resolution_.y;
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferDesc.RefreshRate.Numerator = 0;
    swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.OutputWindow = window.windowHandle_;
    swapChainDesc.SampleDesc.Count = 1;
    swapChainDesc.SampleDesc.Quality = 0;
    swapChainDesc.Windowed = TRUE;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    swapChainDesc.Flags = 0;

    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;
    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
        &featureLevel, 1, D3D11_SDK_VERSION,
        &swapChainDesc, &swapChain_, &device_, nullptr, &deviceContext_
    );
    if (FAILED(hr)) {
        error("Failed to create device and swap chain.");
    }

    ID3D11Texture2D* backBuffer = nullptr;
    swapChain_->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
    device_->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView_);
    backBuffer->Release();

    deviceContext_->OMSetRenderTargets(1, &renderTargetView_, nullptr);
    D3D11_VIEWPORT viewport = {};
    viewport.TopLeftX = 0;
    viewport.TopLeftY = 0;
    viewport.Width = static_cast<float>(window.resolution_.x);
    viewport.Height = static_cast<float>(window.resolution_.y);
    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0f;
    deviceContext_->RSSetViewports(1, &viewport);
}

Renderer::~Renderer() {
    renderTargetView_->Release();
    deviceContext_->Release();
    device_->Release();
    swapChain_->Release();
}

void Renderer::render() {
    float clearColor[] = { 1.0f, 0.2f, 0.4f, 1.0f };
    deviceContext_->ClearRenderTargetView(renderTargetView_, clearColor);
    swapChain_->Present(0, 0);
}