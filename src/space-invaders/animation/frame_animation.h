#pragma once

#include "volumatrix/grid/grid.h"

#include <vector>


class FrameAnimation {
    std::vector<Volumatrix::Vector3<GLubyte>> frame_data;
    float period;
    float current_time;
    int current_frame;
    mutable bool update_animation;

    FrameAnimation(size_t FrameCount, float period);

public:

    FrameAnimation();

    template <size_t FrameCount, size_t FrameSize>
    static FrameAnimation Create(GLubyte (&frames)[FrameCount][FrameSize] , size_t x, size_t y, size_t z, float period){
        FrameAnimation animation{ FrameCount, period };
        for (size_t i = 0; i < FrameCount; ++i) {
            animation.frame_data[i] = Volumatrix::Vector3<GLubyte>(x, y, z, frames[i]);
        }
        return animation;
    }

    void Replace(GLubyte old_value, GLubyte new_value) {
        for (int i = 0; i < frame_data.size(); ++i) {
            frame_data[i].Replace(old_value, new_value);
        }
    }

    const Volumatrix::Vector3<GLubyte>& GetFrame() const;
    bool UpdateRequired() const;
    void Tick(float dt);
    void Draw(Volumatrix::Grid& grid, Volumatrix::Point position) const;
};
