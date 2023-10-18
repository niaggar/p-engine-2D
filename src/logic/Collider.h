#ifndef P_ENGINE_2D_COLLIDER_H
#define P_ENGINE_2D_COLLIDER_H


#include "../models/bodies/Bodie.h"
#include "../models/CollitionProps.h"
#include "../models/bodies/Sphere.h"

class Collider {
public:
    static CollitionProps checkIntersect(Bodie* bodieA, Bodie* bodieB);
    static void separateBodies(Bodie* bodieA, Bodie* bodieB, const CollitionProps& props);
    static void resolveCollision(Bodie* bodieA, Bodie* bodieB, CollitionProps props);

private:
    static CollitionProps intersect(Sphere* bodieA, Sphere* bodieB);
};


#endif //P_ENGINE_2D_COLLIDER_H
