
#include "space-invaders/scripts/entities/behavior_box.h"


namespace SpaceInvaders {

    BehaviorBox::BehaviorBox(
        std::function<Volumatrix::Point(float)> action,
        std::initializer_list<BehaviorBox> children,
        std::initializer_list<std::shared_ptr<Invader>> invaders,
        float start_time):
            action(action),
            children(children),
            invaders(invaders),
            time(start_time) {
        }

    void BehaviorBox::Tick(float dt, const Volumatrix::Point& parent_position) {
        time += dt;
        Volumatrix::Point point = parent_position + action(time);
        for (auto invader: invaders) {
            invader->SetPosition(point);
        }
        for (auto child: children) {
            child.Tick(dt, point);
        }
    }

    void BehaviorBox::Tick(float dt) {
        Tick(dt, {0, 0, 0});
    }
}
