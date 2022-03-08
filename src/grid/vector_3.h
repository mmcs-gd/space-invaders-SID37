#pragma once

#include <vector>


template<typename T>
class Vector3 {
    std::vector<T> vect;
    size_t x_size;
    size_t y_size;
    size_t z_size;

public:
    Vector3():
            vect(0),
            x_size(0),
            y_size(0),
            z_size(0) {
    }


    Vector3(size_t x, size_t y, size_t z, const T* data = nullptr):
            vect(x * y * z),
            x_size(x),
            y_size(y),
            z_size(z) {

        if (data == nullptr) {
            return;
        }

        for (int i = 0; i < Size(); ++i) {
            vect[i] = data[i];
        }
    }

    T* Data() { return vect.data(); }

    constexpr size_t Size() const { return x_size * y_size * z_size; }
    constexpr size_t XSize() const { return x_size; }
    constexpr size_t YSize() const { return y_size; }
    constexpr size_t ZSize() const { return z_size; }


    const T& Get(size_t x, size_t y, size_t z) const {
        return vect[x + x_size * (y + y_size * z)];
    }

    T& Get(size_t x, size_t y, size_t z) {
        return vect[x + x_size * (y + y_size * z)];
    }
};
