#ifndef P_ENGINE_2D_ENGINE_H
#define P_ENGINE_2D_ENGINE_H

#include "../models/bodies/Bodie.h"
#include "../models/bodies/Sphere.h"
#include "../models/Vect2.h"
#include "../models/CollitionProps.h"
#include "../utils/pmath.h"
#include "../utils/enums.h"
#include "Collider.h"
#include "Drawer.h"

class Engine {
public:
    float dt;
    float damping;
    float maxSize;

    Vect2 gravity;
    Vect2 constraint;
    Vect2 origin;

    std::vector<Bodie*> bodies;
    sf::RenderWindow* window;

    Collider* collider;
    Drawer* drawer;

    Engine(float timeStep, float damping, Vect2 constraint, Vect2 origin, sf::RenderWindow* window);
    void update();
    void applyForces();
    void updateBodies();
    void validateCollisions();
    void validateConstraints();
    void addBodiesToMesh();
    void draw();
    void addBodie(Bodie* bodie);
    void randomBodie(ShapeType shape, BodyType type);
    void setGravity(Vect2 gravity);
    void createMesh();
};


#endif //P_ENGINE_2D_ENGINE_H
