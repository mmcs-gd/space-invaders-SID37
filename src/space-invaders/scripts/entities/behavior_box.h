#pragma once

#include "space-invaders/scripts/entities/invader.h"

#include "volumatrix/volumatrix.h"

#include <memory>
#include <initializer_list>
#include <functional>
#include <vector>


namespace SpaceInvaders {

    class BehaviorBox {
        std::function<Volumatrix::Point(float)> action;
        std::vector<BehaviorBox> children;
        std::vector<std::shared_ptr<Invader>> invaders;
        float time;

        void Tick(float dt, const Volumatrix::Point& parent_position);

    public:
        BehaviorBox(
            std::function<Volumatrix::Point(float)> action, float start_time = 0);

        BehaviorBox& AddChild(BehaviorBox&& child);
        void AddInvader(std::shared_ptr<Invader> invader);

        void Tick(float dt);
    };
}

