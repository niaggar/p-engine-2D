//
// Created by nicho on 10/17/2023.
//

#include <iostream>
#include "Sphere.h"

Sphere::Sphere() {
    this->shapeType = ShapeType::SPHERE;
}

Sphere::Sphere(float radius, const Vect2& position, const Vect2& velocity, float mass, float damping, sf::Color color) : Bodie(position, velocity, mass, damping, color) {
    this->radius = radius;

    this->shapeType = ShapeType::SPHERE;
    this->shape = new sf::CircleShape(radius);
    this->shape->setFillColor(color);
}

void Sphere::update(float timeStep) {
    if (this->bodyType == BodyType::STATIC) return;

    this->velocity += (this->force * this->inverseMass) * timeStep;
    this->position += this->velocity * timeStep;

    this->force = Vect2();
}

void Sphere::applyForce(const Vect2& force) {
    this->force += force;
}

void Sphere::collisionBounds(const Vect2& bounds, float damping) {
    if (this->position.x - this->radius < 0.0f)
    {
        this->position.x = this->radius;
        this->velocity.x = -this->velocity.x * damping;
    }
    else if (this->position.x + this->radius > bounds.x)
    {
        this->position.x = bounds.x - this->radius;
        this->velocity.x = -this->velocity.x * damping;
    }

    if (this->position.y - this->radius < 0.0f)
    {
        this->position.y = this->radius;
        this->velocity.y = -this->velocity.y * damping;
    }
    else if (this->position.y + this->radius > bounds.y)
    {
        this->position.y = bounds.y - this->radius;
        this->velocity.y = -this->velocity.y * damping;
    }
}

void Sphere::draw(sf::RenderWindow *window) {
    shape->setPosition(
        this->position.x + this->origin.x - this->radius,
        this->origin.y - this->position.y - this->radius
    );
    window->draw(*shape);
}
