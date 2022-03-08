#pragma once

#include "space-invaders/animation/frame_animation.h"

#include "grid/grid.h"
#include "grid/geometry.h"


class InvaderEntity {
public:
    const FrameAnimation* animation;
    Point location;

    InvaderEntity(Point location, const FrameAnimation* animation):
            location(location),
            animation(animation) {
    }

    void Draw(Grid& grid) {
        animation->Draw(grid, location);
    }
};
