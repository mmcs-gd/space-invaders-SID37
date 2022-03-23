#pragma once

#include "volumatrix/volumatrix.h"


namespace SpaceInvaders {

    class World;


    class Weapon {

    protected:
        World& world;
        Volumatrix::Vector3<GLubyte> icon;
        Volumatrix::Vector3<GLubyte> progress_bar;
        GLubyte material;

        void SetProgress(float value);

    public:
        static const int icon_width = 32;

        Weapon(World& world, const Volumatrix::Vector3<GLubyte>& icon, GLubyte material);

        virtual void Activate();
        virtual void Disactivate();
        virtual void Shot();
        virtual void Tick(float dt);

        virtual void Draw(Volumatrix::Grid& grid, const Volumatrix::Point& position);

        virtual ~Weapon();
    };
}
