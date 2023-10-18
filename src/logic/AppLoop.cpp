#include "AppLoop.h"

#include <SFML/Graphics.hpp>
#include "../utils/prand.h"

AppLoop::AppLoop(int frameRate, const Vect2& windowSize) {
    this->frameRate = frameRate;
    this->windowSize = windowSize;
    this->timeStep = (1.0f / frameRate * 1.0f);

    this->window = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), "pengine2D");
    //this->window->setFramerateLimit(frameRate);

    this->bounds = Vect2(this->windowSize.x, this->windowSize.y);
    this->origin = Vect2(0, this->windowSize.y);
    this->engine = new Engine(this->timeStep, 0.4f, this->bounds, this->origin, this->window);
}

void AppLoop::start() const {
    this->loop();
}

void AppLoop::loop() const {
    while (this->window->isOpen()) {
        sf::Event event;
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->window->close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {

                }

                if (event.key.code == sf::Keyboard::Left) {
                    this->engine->setGravity(Vect2(-98.1f, 0.0f));
                }

                if (event.key.code == sf::Keyboard::Right) {
                    this->engine->setGravity(Vect2(98.1f, 0.0f));
                }

                if (event.key.code == sf::Keyboard::Up) {
                    this->engine->setGravity(Vect2(0.0f, 98.1f));
                }

                if (event.key.code == sf::Keyboard::Down) {
                    this->engine->setGravity(Vect2(0.0f, -98.1f));
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    float mass = prand::getRandom(5.0f, 25.0f);
                    float radius = mass * 2.0f;

                    Vect2 position(event.mouseButton.x + this->origin.x, this->origin.y - event.mouseButton.y);
                    Sphere *body = new Sphere(radius, position, Vect2(), mass, 0.5f, sf::Color::White);
                    body->setOrigin(this->origin);
                    body->bodyType = BodyType::DYNAMIC;

                    this->engine->addBodie(body);
                }

                if (event.mouseButton.button == sf::Mouse::Right) {
                    float mass = prand::getRandom(5.0f, 25.0f);
                    float radius = mass * 2.0f;

                    Vect2 position(event.mouseButton.x + this->origin.x, this->origin.y - event.mouseButton.y);
                    Sphere *body = new Sphere(radius, position, Vect2(), mass, 0.5f, sf::Color::Red);
                    body->setOrigin(this->origin);
                    body->bodyType = BodyType::STATIC;

                    this->engine->addBodie(body);
                }
            }
        }

        this->update();

        this->window->clear();
        this->draw();
        this->window->display();
    }
}

void AppLoop::update() const {
    engine->update();
}

void AppLoop::draw() const {
    engine->draw();
}
