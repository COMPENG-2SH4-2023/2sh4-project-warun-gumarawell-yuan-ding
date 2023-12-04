cmake_minimum_required(VERSION 3.10)  # Specify the minimum version of CMake required

# Set your project name and version
project(SnakeGame VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable with both C++ and C source files
add_executable(SnakeGame
        project.cpp
        GameMechs.cpp
        objPos.cpp
        objPosArrayList.cpp
        Player.cpp
        MacUILib.c
)

# If there are any include directories, add them here
#include_directories(include)

# If you have external libraries to link, add them here
#target_link_libraries(SnakeGame PUBLIC SomeLibrary)
