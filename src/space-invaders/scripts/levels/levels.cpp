#include "space-invaders/scripts/levels/levels.h"

#include "space-invaders/assets/assets.h"

#include <vector>
#include <cmath>


namespace SpaceInvaders {
    namespace Levels {


        void level_1(World& world);
        void level_2(World& world);
        void level_3(World& world);

        std::vector<void(*)(World& world)> level_list {
            level_1,
            level_2,
            level_3
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

            world.AddBehavior(BehaviorBox{
                [](float t) {
                    float angle_step = pi / 10;
                    t = discretize(t, 0.5) * angle_step;
                    return circle_point({2, 100, 55}, 40, t);
                }, {},
                {
                    world.MakeInvader(FrameAnimation::Create(Assets::invader_1, 6, 8, 8, 1), 1, {
                        {2, World::COLOR_INVADER_0},
                        {1, World::COLOR_INVADER_1},
                    })
                }
                });
        }

        void level_2(World& world) {
            world.UpdateMaterial(World::COLOR_INVADER_0, {{0, 0, 0}, 1});
            world.UpdateMaterial(World::COLOR_INVADER_1, {{0.5, 0.5, 0.5}, 1});

            world.AddBehavior(BehaviorBox{
                [&world, last_step = 0] (float t) mutable {
                    int step = discretize(t, 1);
                    float angle_step = pi / 10;
                    t = step * angle_step;
                    auto result = circle_point({2, 100, 55}, 40, t);
                    if (last_step != step) {
                        last_step = step;
                        world.AddBullet(Bullet{world, {2, 2, 2}, result + Volumatrix::Point{1, 3, 8}, World::COLOR_BULLET, { 10, 10, 20 }, 100});
                    }
                    return result;
                }, {},
                {
                    world.MakeInvader(FrameAnimation::Create(Assets::invader_1, 6, 8, 8, 1), 1, {
                        {2, World::COLOR_INVADER_0},
                        {1, World::COLOR_INVADER_1},
                    })
                }
            });
        }


        void level_3(World& world) {
            world.UpdateMaterial(World::COLOR_INVADER_0, {{0, 0, 0}, 1});
            world.UpdateMaterial(World::COLOR_INVADER_1, {{0.7, 0.3, 0.0}, 1});

            world.AddBehavior(BehaviorBox{
                [] (float t) mutable {
                    int step = discretize(t, 1);
                    return Volumatrix::Point{2, 70, 15 + step * 5};
                }, {
                    BehaviorBox{[](float t) { return Volumatrix::Point{0, 0, 0}; }, {}, {
                        world.MakeInvader(FrameAnimation::Create(Assets::invader_2, 5, 11, 8, 0.5), 1, {
                            {2, World::COLOR_INVADER_0},
                            {1, World::COLOR_INVADER_1},
                        })}},
                    BehaviorBox{[](float t) { return Volumatrix::Point{0, 20, 0}; }, {}, {
                        world.MakeInvader(FrameAnimation::Create(Assets::invader_2, 5, 11, 8, 0.5), 1, {
                            {2, World::COLOR_INVADER_0},
                            {1, World::COLOR_INVADER_1},
                        })}},
                    BehaviorBox{[](float t) { return Volumatrix::Point{0, 40, 0}; }, {}, {
                        world.MakeInvader(FrameAnimation::Create(Assets::invader_2, 5, 11, 8, 0.5), 1, {
                            {2, World::COLOR_INVADER_0},
                            {1, World::COLOR_INVADER_1},
                        })}},
                    BehaviorBox{[](float t) { return Volumatrix::Point{0, 60, 0}; }, {}, {
                        world.MakeInvader(FrameAnimation::Create(Assets::invader_2, 5, 11, 8, 0.5), 1, {
                            {2, World::COLOR_INVADER_0},
                            {1, World::COLOR_INVADER_1},
                        })}},
                    BehaviorBox{[](float t) { return Volumatrix::Point{0, 80, 0}; }, {}, {
                        world.MakeInvader(FrameAnimation::Create(Assets::invader_2, 5, 11, 8, 0.5), 1, {
                            {2, World::COLOR_INVADER_0},
                            {1, World::COLOR_INVADER_1},
                        })}},
                    BehaviorBox{[](float t) { return Volumatrix::Point{0, 100, 0}; }, {}, {
                        world.MakeInvader(FrameAnimation::Create(Assets::invader_2, 5, 11, 8, 0.5), 1, {
                            {2, World::COLOR_INVADER_0},
                            {1, World::COLOR_INVADER_1},
                        })}},
                },
            });
        }
    }
}
