#include "Bodie.h"

Bodie::Bodie() = default;

Bodie::Bodie(const Vect2& position, const Vect2& velocity, float mass, float damping, sf::Color color) {
    this->position = position;
    this->velocity = velocity;
    this->mass = mass;
    this->inverseMass = 1 / mass;
    this->damping = damping;
    this->color = color;
    this->bodyType = BodyType::DYNAMIC;
}

void Bodie::setOrigin(const Vect2 &origin) {
    this->origin = origin;
}
