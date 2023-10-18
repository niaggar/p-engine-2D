#ifndef P_ENGINE_2D_BODIE_H
#define P_ENGINE_2D_BODIE_H

#include <SFML/Graphics.hpp>
#include "../Vect2.h"
#include "../../utils/enums.h"

class Bodie {
public:
    Vect2 position;
    Vect2 velocity;
    Vect2 force;
    Vect2 origin;

    float theta;
    float angularVelocity;
    float torque;

    float mass;
    float inverseMass;
    float damping;
    BodyType bodyType;
    ShapeType shapeType;

    sf::Color color;

    Bodie();
    Bodie(const Vect2& position, const Vect2& velocity, float mass, float damping, sf::Color color);

    virtual void update(float timeStep) = 0;
    virtual void applyForce(const Vect2& force) = 0;
    virtual void collisionBounds(const Vect2& bounds, float damping) = 0;
    virtual void draw(sf::RenderWindow* window) = 0;

    void setOrigin(const Vect2& origin);
};


#endif //P_ENGINE_2D_BODIE_H
