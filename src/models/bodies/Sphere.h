#ifndef P_ENGINE_2D_SPHERE_H
#define P_ENGINE_2D_SPHERE_H

#include <SFML/Graphics.hpp>
#include "Bodie.h"

class Sphere : public Bodie {
public:
    float radius;
    sf::CircleShape* shape;

    Sphere();
    Sphere(float radius, const Vect2& position, const Vect2& velocity, float mass, float damping, sf::Color color);

    void update(float timeStep) override;
    void applyForce(const Vect2& force) override;
    void collisionBounds(const Vect2& bounds, float damping) override;
    void draw(sf::RenderWindow* window) override;
};


#endif //P_ENGINE_2D_SPHERE_H
