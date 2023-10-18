#ifndef P_ENGINE_2D_COLLITIONPROPS_H
#define P_ENGINE_2D_COLLITIONPROPS_H

#include "Vect2.h"

struct CollitionProps {
    Vect2 normal;
    bool isColliding;
    float overlap;

    CollitionProps() {
        normal = Vect2();
        isColliding = false;
        overlap = 0;
    }

    CollitionProps(const Vect2& normal, bool isColliding, float overlap) {
        this->normal = normal;
        this->isColliding = isColliding;
        this->overlap = overlap;
    }
};


#endif //P_ENGINE_2D_COLLITIONPROPS_H
