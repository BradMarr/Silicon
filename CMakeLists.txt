cmake_minimum_required(VERSION 3.20)

project("Silicon" LANGUAGES CXX)

if(NOT WIN32)
  message(FATAL_ERROR "${PROJECT_NAME} requires Windows (uses DirectX 11 and Win32).")
endif()

file(GLOB SOURCES "src/source/*.cpp")

add_library(${PROJECT_NAME} STATIC ${SOURCES} )

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/include")
target_link_libraries(${PROJECT_NAME} PRIVATE d3d11)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)
