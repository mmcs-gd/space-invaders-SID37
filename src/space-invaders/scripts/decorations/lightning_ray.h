#pragma once

#include "space-invaders/scripts/decorations/decoration.h"



namespace SpaceInvaders {

    class LightningRay: public Decoration {
        Volumatrix::Vector3<GLubyte> mesh;
        Volumatrix::Point position;
        Volumatrix::GridColor light;

        bool kill = false;

    public:
        LightningRay(World& world, Volumatrix::Point position, Volumatrix::Point size, Volumatrix::GridColor light);

        virtual void Tick(float dt) override;
        virtual void Draw(Volumatrix::Grid& grid) override;
        virtual void Illuminate(Volumatrix::Grid& grid) override;
    };
}
