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

    int current_invader = 0;
    int direction = 5;
    int invaders_location = 0;
    float last_time = 0;

public:
    GameScene(Game& game);

    virtual void Tick(float dt) override;
};
