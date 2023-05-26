#include "model\sphereObject.h"

SphereObject::SphereObject(sf::Vector2f position, sf::Vector2f velocity, float radius, float mass){
    this->shape = new sf::CircleShape(radius);
    this->shape->setPosition(position);
    this->velocity = velocity;
    this->mass = mass;
}

float SphereObject::getRadius()
{
    return radius;
}