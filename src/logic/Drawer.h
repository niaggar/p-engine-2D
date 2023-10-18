#ifndef P_ENGINE_2D_DRAWER_H
#define P_ENGINE_2D_DRAWER_H

#include <SFML/Graphics.hpp>
#include "../models/bodies/Sphere.h"
#include "../models/Vect2.h"

class Drawer {
public:
    Vect2 origin;
    sf::RenderWindow* window;

    Drawer(sf::RenderWindow* window, const Vect2& origin);

    void drawSphere(Sphere* sphere);
};


#endif //P_ENGINE_2D_DRAWER_H
