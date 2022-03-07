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

    const char* scene_fragment_shader = R"(#version 300 es

        precision lowp float;
        precision lowp usampler3D;

        uniform vec2 screen_size;
        uniform vec3 grid_size;
        uniform usampler3D grid_texture;

        struct Material {
            vec4 color;
        };

        layout (std140) uniform materials_block {
            Material[16] materials;
        };

        out vec4 color;


        uvec4 get_voxel(ivec3 location) {
            return texelFetch(grid_texture, location, 0);
        }

        void main() {
            float screen_min = min(screen_size.x, screen_size.y);
            vec3 ray = normalize(vec3(
                    screen_min,
                    gl_FragCoord.x - screen_size.x * 0.5,
                    -(gl_FragCoord.y - screen_size.y * 0.5)
                ) + vec3(0.001, 0.001, 0.001)
            );
            vec3 point = vec3(0, (ray.yz * grid_size.yz) / ray.x + grid_size.yz * 0.5);

            vec3 result_color = vec3(0);
            float ray_color = 1.0;

            ivec2 direction = ivec2(sign(ray.yz));
            vec2 step = abs(ray.x / ray.yz);
            vec2 delta_length = (vec2(direction) * (vec2(0.5) - fract(point.yz)) + vec2(0.5)) * step;

            ivec3 voxel_location = ivec3(point);


            for (int i = 0; i < 8; ++i) {
                uint voxel = get_voxel(voxel_location).w;
                result_color += materials[voxel].color.xyz * ray_color;
                ray_color *= 1.0 - materials[voxel].color.w;

                if (delta_length.y < 1.0 && delta_length.y < delta_length.x) {
                    voxel_location.z += direction.y;
                    uint y_voxel = get_voxel(voxel_location).w;
                    result_color += materials[y_voxel].color.xyz * ray_color * vec3(0.8, 0.8, 1);
                    ray_color *= 1.0 - materials[y_voxel].color.w;
                    delta_length.y += step.y;
                }
                if (delta_length.x < 1.0) {
                    voxel_location.y += direction.x;
                    uint x_voxel = get_voxel(voxel_location).w;
                    result_color += materials[x_voxel].color.xyz * ray_color * vec3(0.8, 1, 0.8);
                    ray_color *= 1.0 - materials[x_voxel].color.w;
                    delta_length.x += step.x;
                }
                if (delta_length.y < 1.0) {
                    voxel_location.z += direction.y;
                    uint y_voxel = get_voxel(voxel_location).w;
                    result_color += materials[y_voxel].color.xyz * ray_color * vec3(0.8, 0.8, 1);
                    ray_color *= 1.0 - materials[y_voxel].color.w;
                    delta_length.y += step.y;
                }

                delta_length -= vec2(1);
                voxel_location.x += 1;
            }

            color = vec4(result_color, 1.0 - ray_color);
        }
    )";
}
