#pragma once

#include <string>

namespace Logger {
    void Log(const char* module, const char* log);
    void Log(const char* module, const std::string& log);
}
