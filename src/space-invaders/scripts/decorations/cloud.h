#pragma once

#include "space-invaders/scripts/decorations/decoration.h"



namespace SpaceInvaders {

    class Cloud: public Decoration {
        Volumatrix::Point position;
        Volumatrix::Vector3<GLubyte> mesh;
        float location;
        float speed_from;
        float speed_to;

    public:
        Cloud(World& world, Volumatrix::Point position, Volumatrix::Point size, float speed_from, float speed_to);

        virtual void Tick(float dt) override;
        virtual void Draw(Volumatrix::Grid& grid) override;
    };
}
