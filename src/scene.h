#pragma once

class Scene {
public:

    enum MouseButtonType {
        BUTTON_LEFT = SDL_BUTTON_LEFT,
        BUTTON_MIDDLE = SDL_BUTTON_MIDDLE,
        BUTTON_RIGHT = SDL_BUTTON_RIGHT,
        BUTTON_X1 = SDL_BUTTON_X1,
        BUTTON_X2 = SDL_BUTTON_X2,
    };

    virtual void Tick(float dt) = 0;

    virtual void EventKeyDown(SDL_KeyCode) { }
    virtual void EventKeyUp(SDL_KeyCode key) { }
    virtual void EventMove(int x, int y) { }
    virtual void EventButtonDown(MouseButtonType button, int x, int y) { }
    virtual void EventButtonUp(MouseButtonType button, int x, int y) { }
    virtual void EventWheel(int delta) { }

    virtual ~Scene() {}
};
