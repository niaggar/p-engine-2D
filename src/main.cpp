#include <iostream>
#include <SFML/Graphics.hpp>
#include "logic/AppLoop.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto* appLoop = new AppLoop(60, Vect2(1200, 900));
    appLoop->start();

    return 0;
}
