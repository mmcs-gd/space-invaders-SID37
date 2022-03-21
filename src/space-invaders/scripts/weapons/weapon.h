#pragma once

#include "volumatrix/volumatrix.h"


namespace SpaceInvaders {

    class World;


    class Weapon {

    protected:
        World& world;
        Volumatrix::Vector3<GLubyte> icon;

    public:
        static const int icon_width = 32;

        Weapon(World& world, const Volumatrix::Vector3<GLubyte>& icon):
                world(world),
                icon(icon) {
        };

        virtual void Activate() { };
        virtual void Disactivate() { };
        virtual void Shot() { };
        virtual void Tick(float dt) { };

        virtual const Volumatrix::Vector3<GLubyte>& GetIcon() const {
            return icon;
        };

        virtual ~Weapon() { }
    };
}
