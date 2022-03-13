#pragma once

#include "space-invaders/animation/frame_animation.h"

#include "volumatrix/grid/grid.h"
#include "volumatrix/grid/geometry.h"



namespace SpaceInvaders {

    class InvaderEntity {
    public:
        const FrameAnimation* animation;
        Volumatrix::Point location;

        InvaderEntity(Volumatrix::Point location, const FrameAnimation* animation):
                location(location),
                animation(animation) {
        }

        void Draw(Volumatrix::Grid& grid) {
            animation->Draw(grid, location);
        }
    };
}
