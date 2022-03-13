#include "volumatrix/graphics/gl_helper.h"

#include <GLES3/gl3.h>
#include <stdexcept>
#include <string>

namespace Volumatrix {

    void checkOpenGLerror() {
        GLenum errCode;
        if ((errCode = glGetError()) != GL_NO_ERROR) {
            throw std::runtime_error((std::string("opengl code ") + std::to_string(errCode)).c_str());
        }
    }
}
