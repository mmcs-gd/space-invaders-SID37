#include "graphics/shaders.h"

namespace Shaders {
    const char* vertex_shader = R"(#version 300 es

        in vec2 coord;
        void main() {
            gl_Position = vec4(coord, 0.0, 1.0);
        }
    )";

    const char* background_fragment_shader = R"(#version 300 es

        precision lowp float;
        precision lowp usampler3D;

        out vec4 color;

        float rand(vec2 co){
            return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453);
        }

        void main() {
            color = vec4(vec3(rand(gl_FragCoord.xy) * 0.1), 1);
        }
    )";
}
