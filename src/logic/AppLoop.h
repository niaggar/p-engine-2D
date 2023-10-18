#ifndef P_ENGINE_2D_APPLOOP_H
#define P_ENGINE_2D_APPLOOP_H

#include <SFML/Graphics.hpp>
#include "../models/bodies/Bodie.h"
#include "../models/bodies/Sphere.h"
#include "../models/Vect2.h"
#include "../models/CollitionProps.h"
#include "../utils/pmath.h"
#include "../utils/enums.h"
#include "Engine.h"

class AppLoop {
public:
    int frameRate;
    float timeStep;
    Vect2 windowSize;
    Vect2 bounds;
    Vect2 origin;
    Engine* engine;
    sf::RenderWindow* window;

    AppLoop(int frameRate, const Vect2& windowSize);
    void start() const;
    void loop() const;
    void update() const;
    void draw() const;
};


#endif //P_ENGINE_2D_APPLOOP_H
