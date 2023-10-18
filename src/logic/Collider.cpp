#include "Collider.h"

#include <cmath>
#include "../models/bodies/Bodie.h"
#include "../models/bodies/Sphere.h"
#include "../models/Vect2.h"
#include "../models/CollitionProps.h"
#include "../utils/pmath.h"
#include "../utils/enums.h"

CollitionProps Collider::checkIntersect(Bodie *bodieA, Bodie *bodieB) {
    auto typeA = bodieA->shapeType;
    auto typeB = bodieB->shapeType;

    if (typeA == ShapeType::SPHERE) {
        switch (typeB)
        {
            case ShapeType::SPHERE:
                return intersect((Sphere*)bodieA, (Sphere*)bodieB);

            case ShapeType::POLYGON:
                return {};
        }
    }

    else if (typeA == ShapeType::POLYGON) {
        switch (typeB)
        {
            case ShapeType::SPHERE:
                return {};

            case ShapeType::POLYGON:
                return {};
        }
    }

    return {};
}

void Collider::separateBodies(Bodie *bodieA, Bodie *bodieB, const CollitionProps& props) {
    if (bodieA->bodyType == BodyType::STATIC) {
        bodieB->position -= props.normal * props.overlap;
    }
    if (bodieB->bodyType == BodyType::STATIC) {
        bodieA->position += props.normal * props.overlap;
    }
    else {
        bodieA->position += props.normal * props.overlap / 2;
        bodieB->position -= props.normal * props.overlap / 2;
    }
}

void Collider::resolveCollision(Bodie *bodieA, Bodie *bodieB, CollitionProps props) {
    auto typeA = bodieA->bodyType;
    auto typeB = bodieB->bodyType;

    if (typeA == BodyType::STATIC && typeB == BodyType::STATIC) {
        return;
    }

    float reduced_mass = 1.f / (bodieA->inverseMass + bodieB->inverseMass);
    auto vA = bodieA->velocity;
    auto vB = bodieB->velocity;

    Vect2 relativeVelocity = vA - vB;
    float velocityAlongNormal = pmath::dot(props.normal, relativeVelocity);
    if (velocityAlongNormal > 0) {
        return;
    }

    float e = std::min(bodieA->damping, bodieB->damping);
    Vect2 impulse = props.normal * (-velocityAlongNormal * (1.f + e)) * reduced_mass;

    if (typeA == BodyType::DYNAMIC)
        bodieA->velocity += impulse * bodieA->inverseMass;
    if (typeB == BodyType::DYNAMIC)
        bodieB->velocity -= impulse * bodieB->inverseMass;
}

CollitionProps Collider::intersect(Sphere *bodieA, Sphere *bodieB) {
    float minDist = bodieA->radius + bodieB->radius;
    float minDist2 = minDist * minDist;
    float dist2 = pmath::distanceSquared(bodieA->position, bodieB->position);

    if (dist2 < minDist2) {
        float dist = std::sqrt(dist2);

        Vect2 normal = (bodieA->position - bodieB->position) / dist;
        float overlap = minDist - dist;

        return {normal, true, overlap};
    }

    return {};
}
