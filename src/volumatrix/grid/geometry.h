#pragma once

#include <GLES3/gl3.h>
#include <cstdlib>
#include <algorithm>


namespace Volumatrix {

    struct Point {
        int x;
        int y;
        int z;

        Point operator-(const Point& p) const {
            return {x - p.x, y - p.y, z - p.z};
        }

        Point operator+(const Point& p) const {
            return {x + p.x, y + p.y, z + p.z};
        }

        Point operator*(int v) const {
            return {x * v, y * v, z * v};
        }

        Point operator/(int v) const {
            return {x / v, y / v, z / v};
        }

        bool operator==(const Point& p) const {
            return z == p.z && y == p.y && x == p.x;
        }

        bool operator!=(const Point& p) const {
            return z != p.z || y != p.y || x != p.x;
        }
    };


    struct GlslVec4 {
        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat w;
    };


    struct GridMaterial {
        struct Color { GLfloat r, g, b; };

        GlslVec4 color;
        GlslVec4 options;

        GridMaterial(Color color = { 0, 0, 0 }, GLfloat reflection = 0, GLfloat density = 0):
            color { color.r, color.g, color.b, 1 },
            options { reflection, density, 0, 0 } {
        }

        GLfloat Reflection() const {
            return options.x;
        }

        GLfloat Density() const {
            return options.y;
        }
    };


    struct GridColor {
        GLubyte r;
        GLubyte g;
        GLubyte b;

        GridColor& operator+=(const GridColor& c) {
            r = GLubyte(std::min(int(r) + c.r, 255));
            g = GLubyte(std::min(int(g) + c.g, 255));
            b = GLubyte(std::min(int(b) + c.b, 255));
            return *this;
        }

        GridColor operator*(float v) {
            return {
                GLubyte(std::min(r * v, 255.0f)),
                GLubyte(std::min(g * v, 255.0f)),
                GLubyte(std::min(b * v, 255.0f))
            };
        }
    };


    struct GridPoint {
        GridColor light;
        GLubyte material;
    };
}
