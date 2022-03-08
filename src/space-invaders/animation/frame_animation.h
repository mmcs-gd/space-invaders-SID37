#pragma once

#include "grid/grid.h"

#include <vector>


class FrameAnimation {
    std::vector<Vector3<GLubyte>> frame_data;
    float period;
    float current_time;
    int current_frame;
    mutable bool update_animation;

    FrameAnimation(size_t FrameCount, float period);

public:

    template <size_t FrameCount, size_t FrameSize>
    static FrameAnimation Create(GLubyte (&frames)[FrameCount][FrameSize] , size_t x, size_t y, size_t z, float period){
        FrameAnimation animation{ FrameCount, period };
        for (size_t i = 0; i < FrameCount; ++i) {
            animation.frame_data[i] = Vector3<GLubyte>(x, y, z, frames[i]);
        }
        return animation;
    }

    bool UpdateRequired() const;
    void Tick(float dt);
    void Draw(Grid& grid, Point position) const;
};