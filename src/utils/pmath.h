#ifndef P_ENGINE_2D_PMATH_H
#define P_ENGINE_2D_PMATH_H

#include "../models/Vect2.h"

namespace pmath {
    const float PI = 3.14159265358979323846f;
    const float RAD_DEG = 180.0f / PI;
    const float DEG_RAD = PI / 180.0f;

    float length(Vect2 &a);
    float lengthSquared(Vect2 &a);
    float distance(Vect2 &a, Vect2 &b);
    float distanceSquared(Vect2 &a, Vect2 &b);
    float dot(Vect2 &a, Vect2 &b);
    float cross(Vect2 &a, Vect2 &b);
    Vect2 normalize(Vect2 &a);
}

#endif //P_ENGINE_2D_PMATH_H
