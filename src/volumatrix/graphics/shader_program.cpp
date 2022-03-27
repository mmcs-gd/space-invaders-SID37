#include "volumatrix/graphics/shader_program.h"
#include "volumatrix/graphics/gl_helper.h"
#include "volumatrix/tools/logger.h"

#include <stdexcept>
#include <vector>


namespace Volumatrix {

    ShaderProgram::ShaderProgram(const char *vertex_shader, const char *fragment_shader) {
        Logger::Log("Graphics", "compiling vertex shader...");
        GLuint vertex_program = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_program, 1, &vertex_shader, nullptr);
        glCompileShader(vertex_program);
        ShaderLog(vertex_program);

        Logger::Log("Graphics", "compiling fragment shader...");
        GLuint fragment_program = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_program, 1, &fragment_shader, nullptr);
        glCompileShader(fragment_program);
        ShaderLog(fragment_program);

        Logger::Log("Graphics", "linking shader program...");
        program = glCreateProgram();
        glAttachShader(program, vertex_program);
        glAttachShader(program, fragment_program);

        glLinkProgram(program);
        GLint status;
        glGetProgramiv(program, GL_LINK_STATUS, &status);
        if (!status) {
            throw std::runtime_error("could not attach shaders");
        }
        checkOpenGLerror();
    }


    void ShaderProgram::ShaderLog(GLuint shader) const {
        GLint log_length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);
        if (log_length > 1) {
            std::vector<GLchar> log_string(log_length);
            glGetShaderInfoLog(shader, log_length, &log_length, log_string.data());
            Logger::Log("Graphics", std::string("shader log: ") + log_string.data());
        }
    }


    GLint ShaderProgram::GetAttribLocation(const char *name) const {
        GLint index = glGetAttribLocation(program, name);
        if (index == -1) {
            throw std::runtime_error((std::string("could not bind attrib ") + name).c_str());
        }
        return index;
    }


    GLint ShaderProgram::GetUniform(const char *name) const {
        GLint index = glGetUniformLocation(program, name);
        if (index == -1) {
            throw std::runtime_error((std::string("could not bind uniform ") + name).c_str());
        }
        return index;
    }


    GLuint ShaderProgram::GetUnifBlock(const char *name) const {
        GLuint index = glGetUniformBlockIndex(program, name);
        if (index == GL_INVALID_INDEX) {
            throw std::runtime_error((std::string("could not bind uniform ") + name).c_str());
        }
        return index;
    }


    void ShaderProgram::Use() {
        glUseProgram(program);
    }


    ShaderProgram::~ShaderProgram() {
        glUseProgram(0);
        glDeleteProgram(program);
    }
}
