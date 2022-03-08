#pragma once

#include "space-invaders/animation/frame_animation.h"
#include "space-invaders/entities/invader_entity.h"
#include "scene.h"
#include "game.h"

#include <vector>

class EditorScene: public Scene {
    Game& game;
    Vector3<GLubyte> result;
    int depth;
    bool update_grid;

    int location_x;
    int location_y;

public:
    EditorScene(Game& game);

    virtual void EventKeyDown(SDL_KeyCode key) override;
    virtual void EventButtonDown(MouseButtonType button, int x, int y) override;
    virtual void EventMove(int x, int y) override;
    virtual void EventWheel(int delta) override;


    virtual void Tick(float dt) override;
};
