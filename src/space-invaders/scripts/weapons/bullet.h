#pragma once

#include "volumatrix/volumatrix.h"

namespace SpaceInvaders {

    class World;


    class Bullet {
        Volumatrix::Vector3<GLubyte> mesh;
        Volumatrix::Point position;
        Volumatrix::Point size;
        Volumatrix::GridColor light;
        World& world;
        float damage;
        float speed;
        float location;

    public:
        bool alive = true;

        Bullet(World& world,
            Volumatrix::Point size, Volumatrix::Point position, GLubyte material,
            Volumatrix::GridColor light, float speed, float damage = 1);

        const Volumatrix::Point& Size() const;
        const Volumatrix::Point& Position() const;
        float Damage() const;
        float Speed() const;

        void Tick(float dt);
        void Draw(Volumatrix::Grid& grid) const;
        void Illuminate(Volumatrix::Grid& grid) const;
    };
}
