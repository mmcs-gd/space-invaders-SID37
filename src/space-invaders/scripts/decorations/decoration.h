#pragma once

#include <volumatrix/volumatrix.h>


namespace SpaceInvaders {

    class World;

    class Decoration {
    protected:
        World& world;

    public:
        bool alive;

        Decoration(World& world): world(world), alive(true) { }

        virtual void Tick(float dt) { }
        virtual void Draw(Volumatrix::Grid& grid) { }
        virtual void Illuminate(Volumatrix::Grid& grid) { }

        virtual ~Decoration() { }
    };
}
