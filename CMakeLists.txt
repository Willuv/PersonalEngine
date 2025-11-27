cmake_minimum_required(VERSION 3.15)
project(PersonalEngine)

find_package(SDL2 CONFIG REQUIRED)

add_executable(PersonalEngine
    FirstGame/main.cpp
    src/Core/Engine.cpp
    src/Platform/Window.cpp
)

target_include_directories(PersonalEngine PRIVATE
    src/Core
    src/Platform
)

target_link_libraries(PersonalEngine PRIVATE SDL2::SDL2 SDL2::SDL2main)
