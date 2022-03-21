#pragma once

#include "space-invaders/animation/frame_animation.h"
#include "space-invaders/scripts/base.h"
#include "space-invaders/scripts/weapons/bullet.h"
#include "volumatrix/volumatrix.h"

#include <memory>


namespace SpaceInvaders {

    class World;


    class Player {
        const float speed = 50;

        FrameAnimation mesh;

        World& world;
        Volumatrix::Point position;

        Direction direction = NONE_DIRECTION;
        float location;

    public:
        const int mesh_width = 13;

        Player(World& world, Volumatrix::Point start_point);

        Volumatrix::Point Size() const;

        void Hit(std::shared_ptr<Bullet> bullet);


        void SetDirection(Direction d);
        const Volumatrix::Point& Position() const;

        void Tick(float dt);
        void Draw(Volumatrix::Grid& grid) const;
    };
}
