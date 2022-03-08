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

    bool PollInputEvent(SDL_Event* event);
    void Draw();

    int Width();
    int Height();
};
