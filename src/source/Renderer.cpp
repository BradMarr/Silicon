//#include "Silicon.hpp"
//
//#include <d3d11.h>
//#include <dxgi1_2.h>
//
//Silicon::Renderer::Renderer(Window window)
//{
//    DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
//    swapChainDesc.BufferCount = 1; // One back buffer
//    swapChainDesc.BufferDesc.Width = window.resolution_.x; // Window width (adjust as needed)
//    swapChainDesc.BufferDesc.Height = window.resolution_.y; // Window height (adjust as needed)
//    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // RGBA format
//    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
//    swapChainDesc.OutputWindow = (HWND)window.windowHandle_; // Your Win32 window handle
//    swapChainDesc.SampleDesc.Count = 1; // No multisampling
//    swapChainDesc.SampleDesc.Quality = 0;
//    swapChainDesc.Windowed = TRUE; // Windowed mode
//    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
//
//    // Create device and swap chain
//    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;
//    HRESULT hr = D3D11CreateDeviceAndSwapChain(
//        nullptr, // Default adapter
//        D3D_DRIVER_TYPE_HARDWARE, // Hardware rendering
//        nullptr, // No software rasterizer
//        0, // No special flags (use D3D11_CREATE_DEVICE_DEBUG for debugging)
//        &featureLevel, 1, // Feature level
//        D3D11_SDK_VERSION,
//        &swapChainDesc,
//        &swapChain_,
//        &device_,
//        nullptr,
//        &deviceContext_
//    );
//    if (FAILED(hr)) {
//        Silicon::error("Failed to create device and swap chain.");
//    }
//
//    // Create render target view
//    ID3D11Texture2D* backBuffer = nullptr;
//    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
//    device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView);
//    backBuffer->Release();
//
//    // Set the render target
//    deviceContext->OMSetRenderTargets(1, &renderTargetView, nullptr);
//
//    // Set up the viewport
//    D3D11_VIEWPORT viewport = {};
//    viewport.Width = 800.0f; // Match swap chain width
//    viewport.Height = 600.0f; // Match swap chain height
//    viewport.MinDepth = 0.0f;
//    viewport.MaxDepth = 1.0f;
//    viewport.TopLeftX = 0;
//    viewport.TopLeftY = 0;
//    deviceContext->RSSetViewports(1, &viewport);
//}
//
//Silicon::Renderer::~Renderer()
//{
//
//}