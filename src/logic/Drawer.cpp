//
// Created by nicho on 10/17/2023.
//

#include "Drawer.h"

Drawer::Drawer(sf::RenderWindow* window, const Vect2& origin) {
    this->window = window;
    this->origin = origin;
}

void Drawer::drawSphere(Sphere *sphere) {
    const auto relativePosition = Vect2(sphere->position.x - this->origin.x, this->origin.y - sphere->position.y);
    const float relativeCenterX = relativePosition.x - sphere->radius;
    const float relativeCenterY = relativePosition.y - sphere->radius;

    sphere->shape->setPosition(relativeCenterX, relativeCenterY);
    window->draw(*sphere->shape);
}
