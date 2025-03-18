cmake_minimum_required(VERSION 3.20)

project("Silicon" LANGUAGES CXX)

if(NOT WIN32)
  message(FATAL_ERROR "${PROJECT_NAME} requires Windows (uses DirectX 11 and Win32).")
endif()

file(GLOB SOURCES "src/source/*.cpp")

add_library(Silicon STATIC ${SOURCES})

target_include_directories(Silicon PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/include")

set_property(TARGET Silicon PROPERTY CXX_STANDARD 23)
set_property(TARGET Silicon PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET Silicon PROPERTY CXX_EXTENSIONS OFF)
