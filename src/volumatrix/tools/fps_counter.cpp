#include "volumatrix/tools/fps_counter.h"
#include "volumatrix/tools/logger.h"

#include <string>


namespace Volumatrix {

    FpsCounter::FpsCounter(int period): period(period) {
    }


    void FpsCounter::Restart() {
        last_time =  std::chrono::system_clock::now();
        tick_count = 0;
    }


    void FpsCounter::Tick() {
        if (tick_count >= period) {
            auto now = std::chrono::system_clock::now();
            auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_time).count();
            auto fps = float(tick_count * 1000) / delta;
            Logger::Log("FPS", std::to_string(fps));
            last_time =  std::chrono::system_clock::now();
            tick_count = 0;
        }
        ++tick_count;
    }
}
