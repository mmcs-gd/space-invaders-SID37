#include "space-invaders/animation/frame_animation.h"

#include "volumatrix/tools/logger.h"


FrameAnimation::FrameAnimation():
        FrameAnimation(0, 0) {
}

FrameAnimation::FrameAnimation(size_t FrameCount, float period):
        frame_data(FrameCount),
        period(period),
        current_time(0),
        current_frame(0),
        update_animation(true) {
}


bool FrameAnimation::UpdateRequired() const {
    return update_animation;
}


const Volumatrix::Vector3<GLubyte>& FrameAnimation::GetFrame() const {
    return frame_data[current_frame];
}


void FrameAnimation::Tick(float dt) {
    current_time += dt;
    while (current_time > period) {
        current_frame = (current_frame + 1) % frame_data.size();
        current_time -= period;
        update_animation = true;
    }
}

void FrameAnimation::Draw(Volumatrix::Grid& grid, Volumatrix::Point position) const {
    grid.StorePoints(frame_data[current_frame], position);
    update_animation = false;
}
