#include "pmath.h"

#include <cmath>

namespace pmath {
    float length(Vect2 &a) {
        return std::sqrt(a.x * a.x + a.y * a.y);
    }

    float lengthSquared(Vect2 &a) {
        return a.x * a.x + a.y * a.y;
    }

    float distance(Vect2 &a, Vect2 &b) {
        return std::sqrt((float)pow(b.x - a.x, 2) + (float)pow(b.y - a.y, 2));
    }

    float distanceSquared(Vect2 &a, Vect2 &b) {
        return (float)pow(b.x - a.x, 2) + (float)pow(b.y - a.y, 2);
    }

    float dot(Vect2 &a, Vect2 &b) {
        return a.x * b.x + a.y * b.y;
    }

    float cross(Vect2 &a, Vect2 &b) {
        return a.x * b.y - a.y * b.x;
    }

    Vect2 normalize(Vect2 &a) {
        float len = length(a);
        return {a.x / len, a.y / len};
    }
}