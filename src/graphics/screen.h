#pragma once

#include <SDL2/SDL.h>

class Screen {
    int width;
    int height;

    SDL_Window* window;

    Screen(const Screen&) = delete;
    Screen(Screen&&) = delete;
    Screen& operator=(const Screen&) = delete;
    Screen& operator=(Screen&&) = delete;

public:
    Screen(const char* title);

    void ProcessingEvents();
    void Draw();

    int Width();
    int Height();
};
