#pragma once

#include <chrono>


class FpsCounter {
    std::chrono::time_point<std::chrono::system_clock> last_time;
    int period;
    int tick_count;

public:
    FpsCounter(int period);

    void Restart();
    void Tick();
};
