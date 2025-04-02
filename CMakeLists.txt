cmake_minimum_required(VERSION 3.20)

project("Silicon" LANGUAGES CXX)

if(NOT WIN32)
  message(FATAL_ERROR "${PROJECT_NAME} requires Windows (uses DirectX 11 and Win32).")
endif()

file(GLOB SOURCES "src/source/*.cpp")
add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/include")
target_link_libraries(${PROJECT_NAME} PRIVATE d3d11 dxgi d3dcompiler)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)