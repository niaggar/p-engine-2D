#include "Engine.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include "../utils/prand.h"

Engine::Engine(float timeStep, float damping, Vect2 constraint, Vect2 origin, sf::RenderWindow *window) {
    this->dt = timeStep / 8.0f;
    this->maxSize = 25.0f;
    this->constraint = constraint;
    this->origin = origin;
    this->gravity = Vect2(0, -98.1f);
    this->damping = damping;
    this->window = window;

    this->collider = new Collider();
    this->createMesh();

    //this->drawer = new Drawer(this->window, this->origin);

    // ADD A TEST BODY
    this->randomBodie(ShapeType::SPHERE, BodyType::DYNAMIC);
    this->randomBodie(ShapeType::SPHERE, BodyType::DYNAMIC);
    this->randomBodie(ShapeType::SPHERE, BodyType::DYNAMIC);
    this->randomBodie(ShapeType::SPHERE, BodyType::DYNAMIC);
    this->randomBodie(ShapeType::SPHERE, BodyType::DYNAMIC);
}

void Engine::update() {
    for (int i = 0; i < 8; i++) {
        this->applyForces();
        this->updateBodies();
        this->addBodiesToMesh();
        this->validateCollisions();
        this->validateConstraints();
    }
}

void Engine::applyForces() {
    for (auto & bodie : this->bodies) {
        if (bodie->bodyType == BodyType::STATIC) continue;

        bodie->applyForce(this->gravity * bodie->mass);
    }
}

void Engine::updateBodies() {
    for (auto & bodie : this->bodies) {
        bodie->update(this->dt);
    }
}

void Engine::validateCollisions() {
    for (int i = 0; i < static_cast<int>(this->bodies.size()); i++)
    {
        for (int j = i + 1; j < static_cast<int>(this->bodies.size()); j++)
        {
            if (this->bodies[i]->bodyType == BodyType::STATIC && this->bodies[j]->bodyType == BodyType::STATIC) continue;
            CollitionProps haveCollision = this->collider->checkIntersect(this->bodies[i], this->bodies[j]);

            if (haveCollision.isColliding)
            {
                this->collider->separateBodies(this->bodies[i], this->bodies[j], haveCollision);
                this->collider->resolveCollision(this->bodies[i], this->bodies[j], haveCollision);
            }
        }
    }
}

void Engine::validateConstraints() {
    for (auto & bodie : this->bodies) {
        if (bodie->bodyType == BodyType::STATIC) continue;

        bodie->collisionBounds(this->constraint, this->damping);
    }
}

void Engine::addBodiesToMesh() {
    /*this->mesh->clear();

    #pragma omp parallel for
    for (int i = 0; i < static_cast<int>(this->bodies.size()); i++)
    {
        this->mesh->add(i, this->bodies[i]->position);
    }*/
}

void Engine::draw() {
    for (auto & bodie : this->bodies) {
        bodie->draw(this->window);
    }
}

void Engine::addBodie(Bodie *bodie) {
    this->bodies.push_back(bodie);
}

void Engine::randomBodie(ShapeType shape, BodyType type) {
    sf::Color color = sf::Color(prand::getRandom(0, 255), prand::getRandom(0, 255), prand::getRandom(0, 255));

    if (shape == ShapeType::SPHERE) {
        auto radius = prand::getRandom(5.0f, this->maxSize);
        auto position = Vect2(prand::getRandom(0.0f, this->constraint.x), prand::getRandom(0.0f, this->constraint.y));
        auto velocity = Vect2(prand::getRandom(-200.0f, 200.0f), prand::getRandom(-200.0f, 200.0f));
        auto mass = prand::getRandom(1.0f, 10.0f);
        auto damping = prand::getRandom(0.0f, 1.0f);

        auto body = new Sphere(radius, position, velocity, mass, damping, color);
        body->setOrigin(this->origin);
        body->bodyType = type;

        this->bodies.push_back(body);
    }
    else if (shape == ShapeType::POLYGON) {
        //std::vector<vect2> vertices;
        //vertices.push_back(vect2(0, 0));
        //vertices.push_back(vect2(0, radius));
        //vertices.push_back(vect2(radius, radius));
        //vertices.push_back(vect2(radius, 0));

        //this->bodies.push_back(new Polygon(vect2(prand::getRandom(0.0f, this->constraint.X), prand::getRandom(0.0f, this->constraint.Y)), vertices, mass, damping, color, type, this->origin));
    }
}

void Engine::setGravity(Vect2 gravity) {
    this->gravity = gravity;
}

void Engine::createMesh() {
    /*int columns = (int)(this->constraint.X / this->maxSize);
    int rows = (int)(this->constraint.Y / this->maxSize);

    this->mesh = new Mesh(this->constraint, columns, rows);*/
}
