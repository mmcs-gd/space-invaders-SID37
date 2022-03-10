#include "graphics/shaders.h"

namespace Shaders {
    const char* vertex_shader = R"(#version 300 es

        in vec2 coord;
        void main() {
            gl_Position = vec4(coord, 0.0, 1.0);
        }
    )";

    const char* background_fragment_shader = R"(#version 300 es

        precision mediump float;

        out vec4 color;

        float rand(vec2 co){
            return fract(sin(dot(co, vec2(12.9898, 78.233))) * 43758.5453);
        }

        void main() {
            color = vec4(vec3(rand(gl_FragCoord.xy) * 0.1), 1);
        }
    )";

    const char* scene_fragment_shader = R"(#version 300 es

        precision mediump float;
        precision mediump usampler3D;

        uniform vec2 screen_size;
        uniform vec3 grid_size;
        uniform usampler3D grid_texture;

        struct Material {
            vec4 color;
            vec4 options;
        };

        layout (std140) uniform materials_block {
            Material[16] materials;
        };

        out vec4 color;
        const vec3 default_light = vec3(0.3);

        struct RayContexts {
            Material material;
            uvec4 voxel_data;

            ivec3 voxel_location;

            vec3 result_color;
            float ray_color;
            float last_intersect;

            ivec2 direction;
            vec2 step;
            vec2 delta_length;
        } ctx;

        uvec4 get_voxel() {
            return texelFetch(grid_texture, ctx.voxel_location, 0);
        }

        void process_density(float new_intersect) {
            // float delta_intersect = new_intersect - ctx.last_intersect;
            // ctx.result_color += ctx.ray_color * ctx.material.color.xyz * delta_intersect * default_light;
            // ctx.ray_color = max(ctx.ray_color - ctx.material.options.y * delta_intersect, 0.0);

            float delta_intersect = pow(1.0 - ctx.material.options.y, new_intersect - ctx.last_intersect);
            ctx.result_color += ctx.ray_color * ctx.material.color.xyz * (1.0 - delta_intersect) *
                    (default_light + vec3(ctx.voxel_data.xyz) / 256.0);
            ctx.ray_color *= delta_intersect;

            ctx.last_intersect = new_intersect;
        }

        void x_intersect() {
            if (ctx.delta_length.x >= 1.0) return;
            process_density(ctx.delta_length.x);
            ctx.voxel_location.y += ctx.direction.x;
            vec3 last_light = vec3(ctx.voxel_data.xyz) / 256.0;
            ctx.voxel_data = get_voxel();
            ctx.material = materials[ctx.voxel_data.w];
            ctx.result_color += ctx.ray_color * ctx.material.color.xyz * ctx.material.options.x * (default_light * 0.8 + last_light) * 3.0;
            ctx.ray_color *= 1.0 - ctx.material.options.x;
            ctx.delta_length.x += ctx.step.x;
        }

        void y_intersect() {
            if (ctx.delta_length.y >= 1.0) return;
            process_density(ctx.delta_length.y);
            ctx.voxel_location.z += ctx.direction.y;
            vec3 last_light = vec3(ctx.voxel_data.xyz) / 256.0;
            ctx.voxel_data = get_voxel();
            ctx.material = materials[ctx.voxel_data.w];
            ctx.result_color += ctx.material.color.xyz * ctx.material.options.x * ctx.ray_color * (default_light * 0.8 + last_light) * 3.0;
            ctx.ray_color *= 1.0 - ctx.material.options.x;
            ctx.delta_length.y += ctx.step.y;
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

            ctx.result_color = vec3(0);
            ctx.ray_color = 1.0;

            ctx.direction = ivec2(sign(ray.yz));
            ctx.step = abs(ray.x / ray.yz);
            ctx.delta_length = (vec2(ctx.direction) * (vec2(0.5) - fract(point.yz)) + vec2(0.5)) * ctx.step;

            ctx.voxel_location = ivec3(point);


            for (int i = 0; i < 8; ++i) {
                vec3 last_light = vec3(ctx.voxel_data.xyz) / 256.0;
                ctx.voxel_data = get_voxel();
                ctx.material = materials[ctx.voxel_data.w];
                ctx.result_color += ctx.material.color.xyz * ctx.ray_color * ctx.material.options.x * (default_light + last_light) * 3.0;
                ctx.ray_color *= 1.0 - ctx.material.options.x;

                ctx.last_intersect = 0.0;
                if (ctx.delta_length.y < ctx.delta_length.x) y_intersect();
                x_intersect();
                y_intersect();

                process_density(1.0);
                ctx.delta_length -= vec2(1);
                ctx.voxel_location.x += 1;
            }

            color = vec4(ctx.result_color, 1.0 - ctx.ray_color);
        }
    )";
}
