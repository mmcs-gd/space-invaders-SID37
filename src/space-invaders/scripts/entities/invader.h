#pragma once

#include "space-invaders/animation/frame_animation.h"
#include "space-invaders/scripts/weapons/bullet.h"

#include "volumatrix/volumatrix.h"

#include <memory>


namespace SpaceInvaders {

    class World;


    class Invader {
        FrameAnimation animation;
        Volumatrix::Point position;
        World& world;
        float hp;

    public:
        bool alive = true;

        Invader(World& world, const FrameAnimation& animation, float hp, Volumatrix::Point position = {0, 0, 0});

        void Hit(std::shared_ptr<Bullet> bullet);

        Volumatrix::Point Size() const;
        const Volumatrix::Point& Position() const;
        void SetPosition(const Volumatrix::Point& p);

        void Tick(float dt);
        void Draw(Volumatrix::Grid& grid) const;
    };
}
