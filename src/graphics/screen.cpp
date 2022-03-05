#include "graphics/screen.h"

#include <stdexcept>
#include <string>


Screen::Screen(const char* title) {
    static int init_status = SDL_Init(SDL_INIT_VIDEO);
    if (init_status < 0) {
        throw std::runtime_error((std::string("Unable to init SDL: ") + SDL_GetError()).c_str());
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

    SDL_Rect rect;
    SDL_GetDisplayUsableBounds(0, &rect);
    width = rect.w;
    height = rect.h;
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if (window == nullptr) {
        throw std::runtime_error((std::string("Unable to init Window: ") + SDL_GetError()).c_str());
    }

    SDL_GLContext glcontext = SDL_GL_CreateContext(window);
}


void Screen::ProcessingEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                // TODO: event system
            }
            break;
        }
    }
}


void Screen::Draw() {
    SDL_GL_SwapWindow(window);
}


int Screen::Width() {
    return width;
}


int Screen::Height() {
    return height;
}
