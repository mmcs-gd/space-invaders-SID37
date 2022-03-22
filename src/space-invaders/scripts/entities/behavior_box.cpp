
#include "space-invaders/scripts/entities/behavior_box.h"


namespace SpaceInvaders {

    BehaviorBox::BehaviorBox(
        std::function<Volumatrix::Point(float)> action, float start_time):
            action(action),
            children(),
            invaders(),
            time(start_time) {
        }


    BehaviorBox& BehaviorBox::AddChild(BehaviorBox&& child) {
        children.push_back(child);
        return children.back();
    }

    void BehaviorBox::AddInvader(std::shared_ptr<Invader> invader) {
        invaders.push_back(invader);
    }


    void BehaviorBox::Tick(float dt, const Volumatrix::Point& parent_position) {
        time += dt;
        Volumatrix::Point point = parent_position + action(time);
        for (auto invader: invaders) {
            invader->SetPosition(point);
        }
        for (auto& child: children) {
            child.Tick(dt, point);
        }
    }

    void BehaviorBox::Tick(float dt) {
        Tick(dt, {0, 0, 0});
    }
}
