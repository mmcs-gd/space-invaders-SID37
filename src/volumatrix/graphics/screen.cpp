#include "volumatrix/graphics/screen.h"

#include <stdexcept>
#include <string>

namespace Volumatrix {

    Screen::Screen(const char* title) {
        static int init_status = SDL_Init(SDL_INIT_VIDEO);
        if (init_status < 0) {
            throw std::runtime_error((std::string("Unable to init SDL: ") + SDL_GetError()).c_str());
        }

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);

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


    bool Screen::PollInputEvent(SDL_Event* event) {
        while (SDL_PollEvent(event)) {
            switch (event->type) {
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                case SDL_KEYMAPCHANGED:
                case SDL_MOUSEMOTION:
                case SDL_MOUSEBUTTONDOWN:
                case SDL_MOUSEBUTTONUP:
                case SDL_MOUSEWHEEL:
                    return true;
                default: break;
            }
        }
        return false;
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
}
