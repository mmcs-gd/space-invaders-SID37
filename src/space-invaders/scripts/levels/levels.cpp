#include "space-invaders/scripts/levels/levels.h"

#include "space-invaders/assets/assets.h"

#include <vector>
#include <cmath>


namespace SpaceInvaders {
    namespace Levels {


        void level_1(World& world);
        void level_2(World& world);
        void level_3(World& world);
        void level_4(World& world);
        void level_5(World& world);

        std::vector<void(*)(World& world)> level_list {
            level_1,
            level_2,
            level_3,
            level_4,
            level_5,
        };


        void Init(World& world, int level) {
            if (level < 0) return;
            if (level >= level_list.size()) {
                world.Win();
                return;
            }
            level_list[level](world);
        }

        namespace {
            const float pi = 3.1415926535897932;

            int discretize(float time, float step) {
                return (int)(time / step);
            }

            Volumatrix::Point circle_point(Volumatrix::Point point, float r, float angle) {
                return point + Volumatrix::Point{0,
                    (int)(r * std::sin(angle)),
                    (int)(-r * std::cos(angle))
                };
            }
        }


        void level_1(World& world) {
            world.UpdateMaterial(World::COLOR_INVADER_0, {{0, 0, 0}, 1});
            world.UpdateMaterial(World::COLOR_INVADER_1, {{0.5, 0.5, 0.5}, 1});

            auto behavior = world.AddBehavior(BehaviorBox{
                [](float t) {
                    float angle_step = pi / 10;
                    t = discretize(t, 0.5) * angle_step;
                    return circle_point({2, 100, 55}, 40, t);
                }
            });
            FrameAnimation invader_animation = FrameAnimation::Create(Assets::invader_1, 6, 8, 8, 1);
            invader_animation.Replace(2, World::COLOR_INVADER_0);
            invader_animation.Replace(1, World::COLOR_INVADER_1);
            behavior->AddInvader(world.AddInvader(Invader{world, invader_animation, 1}));
        }



        void level_2(World& world) {
            world.UpdateMaterial(World::COLOR_INVADER_0, {{0, 0, 0}, 1});
            world.UpdateMaterial(World::COLOR_INVADER_1, {{0.5, 0.5, 0.5}, 1});

            auto behavior = world.AddBehavior(BehaviorBox{
                [](float t) {
                    float angle_step = pi / 10;
                    t = discretize(t, 1) * angle_step;
                    return circle_point({2, 100, 55}, 40, t);
                }
            });
            FrameAnimation invader_animation = FrameAnimation::Create(Assets::invader_1, 6, 8, 8, 1);
            invader_animation.Replace(2, World::COLOR_INVADER_0);
            invader_animation.Replace(1, World::COLOR_INVADER_1);
            auto invader = world.AddInvader(Invader{world, invader_animation, 1});
            auto invader_size = invader->Size();
            invader->AddGun(Bullet{world, {2, 2, 2}, {0, 0, 0}, World::COLOR_BULLET, { 10, 10, 20 }, 100}, {invader_size.x / 2, invader_size.y / 2 - 1, invader_size.z}, 1);
            behavior->AddInvader(invader);
        }


        void level_3(World& world) {
            world.UpdateMaterial(World::COLOR_INVADER_0, {{0, 0, 0}, 1});
            world.UpdateMaterial(World::COLOR_INVADER_1, {{0.7, 0.3, 0.0}, 1});

            auto main_box = world.AddBehavior(BehaviorBox{
                [] (float t) mutable {
                    int step = discretize(t, 1);
                    return Volumatrix::Point{2, 70, 15 + step * 5};
                }});
            FrameAnimation invader_animation = FrameAnimation::Create(Assets::invader_2, 5, 11, 8, 1);
            invader_animation.Replace(2, World::COLOR_INVADER_0);
            invader_animation.Replace(1, World::COLOR_INVADER_1);

            for (int i = 0; i < 6; ++i) {
                auto& box = main_box->AddChild(BehaviorBox{[i = i](float t) { return Volumatrix::Point{0, i * 20, 0}; }});
                box.AddInvader(world.AddInvader(Invader{world, invader_animation, 1}));
            }
        }


        void level_4(World& world) {
            world.UpdateMaterial(World::COLOR_INVADER_0, {{0, 0, 0}, 1});
            world.UpdateMaterial(World::COLOR_INVADER_1, {{0.7, 0.3, 0.0}, 1});

            auto main_box = world.AddBehavior(BehaviorBox{
                [] (float t) mutable {
                    int step = discretize(t, 1);
                    return Volumatrix::Point{2, 70, 15 + step * 5};
                }});
            FrameAnimation invader_animation = FrameAnimation::Create(Assets::invader_2, 5, 11, 8, 1);
            invader_animation.Replace(2, World::COLOR_INVADER_0);
            invader_animation.Replace(1, World::COLOR_INVADER_1);

            for (int i = 0; i < 6; ++i) {
                auto& box = main_box->AddChild(BehaviorBox{[i = i](float t) { return Volumatrix::Point{0, i * 20, 0}; }});
                auto invader = world.AddInvader(Invader{world, invader_animation, 1});
                auto invader_size = invader->Size();
                invader->AddGun(Bullet{world, {1, 1, 3}, {0, 0, 0}, World::COLOR_BULLET, { 10, 10, 20 }, 100}, {invader_size.x / 2, invader_size.y / 2 - 1, invader_size.z + 5}, 2, i * 2 / 6.0);
                box.AddInvader(invader);
            }
        }


        void level_5(World& world) {
            world.UpdateMaterial(World::COLOR_INVADER_0, {{0, 0, 0}, 1});
            world.UpdateMaterial(World::COLOR_INVADER_1, {{0.7, 0.3, 0.0}, 1});
            world.UpdateMaterial(World::COLOR_INVADER_2, {{0.5, 0.5, 0.5}, 1});

            auto main_box = world.AddBehavior(BehaviorBox{
                [] (float t) mutable {
                    int step = discretize(t, 1);
                    return Volumatrix::Point{2, 0, 40 + step * 5};
                }});
            FrameAnimation invader1_animation = FrameAnimation::Create(Assets::invader_1, 6, 8, 8, 1);
            FrameAnimation invader2_animation = FrameAnimation::Create(Assets::invader_2, 5, 11, 8, 1);
            invader1_animation.Replace(2, World::COLOR_INVADER_0);
            invader1_animation.Replace(1, World::COLOR_INVADER_2);
            invader2_animation.Replace(2, World::COLOR_INVADER_0);
            invader2_animation.Replace(1, World::COLOR_INVADER_1);

            for (int i = 0; i < 2; ++i) {
                Volumatrix::Point center { 0, 50 + i * 150, 0 };
                auto& module_box = main_box->AddChild(BehaviorBox{[center = center](float t) { return center; }});
                auto invader = world.AddInvader(Invader{world, invader2_animation, 1});
                auto invader_size = invader->Size();
                invader->AddGun(Bullet{world, {1, 1, 3}, {0, 0, 0}, World::COLOR_BULLET, { 10, 10, 20 }, 100}, {invader_size.x / 2, invader_size.y / 2 - 1, invader_size.z + 5}, 1);
                module_box.AddInvader(invader);
                for (int j = 0; j < 3; ++j) {
                    auto& box = module_box.AddChild(BehaviorBox{
                        [i, j](float t) {
                            float angle_step = 2 * pi / 18;
                            t = (discretize(t, 1.0f / 6) + 6 * j) * angle_step;
                            return circle_point({0, 0, 0}, 30, (i % 2 == 0) ? t : -t);
                        }
                    });
                    box.AddInvader(world.AddInvader(Invader{world, invader1_animation, 1}));
                }
            }
        }
    }
}
