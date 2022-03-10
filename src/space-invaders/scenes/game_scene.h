#pragma once

#include "space-invaders/animation/frame_animation.h"
#include "space-invaders/entities/invader_entity.h"
#include "scene.h"
#include "game.h"

#include <vector>

class GameScene : public Scene {
    Game& game;
    std::vector<FrameAnimation> animations;
    std::vector<InvaderEntity> invaders;
    std::vector<InvaderEntity> decorations;

    std::shared_ptr<InvaderEntity> player;
    std::shared_ptr<InvaderEntity> player_bullet;

    Vector3<GridColor> bullet_light;

    int current_invader = 0;
    int direction = 5;
    int invaders_location = 0;
    float last_time = 0;

    float move_direction = 0;
    float player_location = 0;
    float bullet_location = 0;

    int invaders_count = 0;


public:
    GameScene(Game& game);

    virtual void EventKeyDown(SDL_KeyCode key) override;
    virtual void EventKeyUp(SDL_KeyCode key) override;
    virtual void EventButtonDown(MouseButtonType button, int x, int y) override;
    virtual void EventButtonUp(MouseButtonType button, int x, int y) override;

    virtual void Tick(float dt) override;
};
