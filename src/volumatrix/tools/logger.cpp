#include "volumatrix/tools/logger.h"
#include <iostream>


namespace Volumatrix {

    namespace Logger {
        void Log(const char* module, const char* log) {
    #ifdef DEBUG
            std::cout << module << ": " << log << std::endl;
    #endif
        }
        
        void Log(const char* module, const std::string& log) {
            Log(module, log.c_str());
        }
    }
}
