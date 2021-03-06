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
        void level_6(World& world);
        void level_victory(World& world);

        std::vector<void(*)(World& world)> level_list {
            level_1,
            level_2,
            level_3,
            level_4,
            level_5,
            level_6,
            level_victory,
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

            Volumatrix::Point ellips_point(Volumatrix::Point point, float rx, float ry, float angle) {
                return point + Volumatrix::Point{0,
                    (int)(rx * std::sin(angle)),
                    (int)(-ry * std::cos(angle))
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
            FrameAnimation invader1_animation = FrameAnimation::Create(Assets::invader_1, 6, 8, 8, 0.3);
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


        void level_6(World& world) {
            world.UpdateMaterial(World::COLOR_INVADER_0, {{0, 0, 0}, 1});
            world.UpdateMaterial(World::COLOR_INVADER_1, {{0.7, 0.3, 0.0}, 1});
            world.UpdateMaterial(World::COLOR_INVADER_2, {{0.5, 0.5, 0.5}, 1});
            world.UpdateMaterial(World::COLOR_INVADER_3, {{0.4, 0, 0.5}, 1});

            auto main_box = world.AddBehavior(BehaviorBox{
                [] (float t) mutable {
                    int step = discretize(t, 2);
                    return Volumatrix::Point{2, 0, 40 + step * 5};
                }});
            FrameAnimation invader1_animation = FrameAnimation::Create(Assets::invader_1, 6, 8, 8, 1);
            FrameAnimation invader2_animation = FrameAnimation::Create(Assets::invader_2, 5, 11, 8, 1);
            FrameAnimation invader3_animation = FrameAnimation::Create(Assets::invader_3, 6, 14, 8, 1);
            invader1_animation.Replace(2, World::COLOR_INVADER_0);
            invader1_animation.Replace(1, World::COLOR_INVADER_2);
            invader2_animation.Replace(2, World::COLOR_INVADER_0);
            invader2_animation.Replace(1, World::COLOR_INVADER_1);
            invader3_animation.Replace(2, World::COLOR_INVADER_0);
            invader3_animation.Replace(1, World::COLOR_INVADER_3);

            for (int i = 0; i < 3; ++i) {
                Volumatrix::Point center { 0, 80 + i * 30, 0 };
                auto& box = main_box->AddChild(BehaviorBox{[center = center](float t) { return center; }});
                auto invader = world.AddInvader(Invader{world, invader3_animation, 3});
                auto invader_size = invader->Size();
                invader->AddGun(
                    Bullet{world, {1, 1, 3}, {0, 0, 0}, World::COLOR_BULLET, { 20, 0, 20 }, 100},
                    {invader_size.x / 2, invader_size.y / 2 - 1, invader_size.z + 7},
                    2, 2.0 * i / 3);
                box.AddInvader(invader);
            }

            Volumatrix::Point main_center { 0, 112, 0 };
            int count = 10;
            for (int i = 0; i < count; ++i) {
                auto& box = main_box->AddChild(BehaviorBox{
                    [i, count, main_center](float t) {
                        float angle_step = 2 * pi / (count * 6);
                        t = (discretize(t, 1.0f / 3) + i * 6 + 1) * angle_step;
                        return ellips_point(main_center, 80, 30, t);
                    }
                });
                box.AddInvader(world.AddInvader(Invader{world, invader1_animation, 0.5}));
            }

            for (int i = 0; i < 2; ++i) {
                Volumatrix::Point center { 0, 10 + i * 182, 40 };
                auto& module_box = main_box->AddChild(BehaviorBox{[center = center](float t) { return center; }});
                auto invader = world.AddInvader(Invader{world, invader2_animation, 1});
                auto invader_size = invader->Size();
                invader->AddGun(Bullet{world, {1, 1, 3}, {0, 0, 0}, World::COLOR_BULLET, { 10, 10, 20 }, 100}, {invader_size.x / 2, invader_size.y / 2 - 1, invader_size.z + 5}, 1);
                module_box.AddInvader(invader);
            }
        }


        void level_victory(World& world) {
            world.SetWeaponInfinity(true);
            world.UpdateMaterial(World::COLOR_INVADER_0, {{0, 0, 0}, 1});
            world.UpdateMaterial(World::COLOR_INVADER_1, {{0.5, 0.5, 0.0}, 1});

            auto main_box = world.AddBehavior(BehaviorBox{[] (float t) { return Volumatrix::Point{2, 30, 50}; }});
            FrameAnimation invader1_animation = FrameAnimation::Create(Assets::invader_1, 6, 8, 8, 1);
            FrameAnimation block_animation = FrameAnimation::Create(Assets::invader_block, 6, 8, 8, 1);
            invader1_animation.Replace(2, World::COLOR_INVADER_0);
            invader1_animation.Replace(1, World::COLOR_INVADER_1);
            block_animation.Replace(1, World::COLOR_INVADER_1);

            auto& w_box = main_box->AddChild(BehaviorBox([](float t) { return Volumatrix::Point{ 0, 0, 0 };}));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 0})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 32, 0})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 8})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 32, 8})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 16})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 32, 16})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 24})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 16, 24})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 32, 24})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 32})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 16, 32})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 32, 32})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 40})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 16, 40})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 32, 40})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 8, 48})));
            w_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 24, 48})));

            auto& i_box = main_box->AddChild(BehaviorBox([](float t) { return Volumatrix::Point{ 0, 72, 0 };}));
            auto& i_dot_box =i_box.AddChild(BehaviorBox([](float t) { return Volumatrix::Point{0, 8, int(-8 * std::sin(t * 2))};}));
            i_dot_box.AddInvader( world.AddInvader(Invader(world, invader1_animation, 1, {0, 0, 0})));
            i_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 16})));
            i_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 8, 16})));
            i_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 8, 24})));
            i_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 8, 32})));
            i_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 8, 40})));
            i_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 48})));
            i_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 8, 48})));
            i_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 16, 48})));

            auto& n_box = main_box->AddChild(BehaviorBox([](float t) { return Volumatrix::Point{ 0, 128, 0 };}));
            n_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 16})));
            n_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 16, 16})));
            n_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 24, 16})));
            n_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 24})));
            n_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 8, 24})));
            n_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 32, 24})));
            n_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 32})));
            n_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 32, 32})));
            n_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 40})));
            n_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 32, 40})));
            n_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 48})));
            n_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 32, 48})));

            auto& e_box = main_box->AddChild(BehaviorBox([](float t) { return Volumatrix::Point{ 0, 192, 0 };}));
            e_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 8})));
            e_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 16})));
            e_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 24})));
            e_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 32})));
            e_box.AddInvader(world.AddInvader(Invader(world, block_animation, 1, {0, 0, 48})));
        }

    }
}
