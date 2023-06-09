#include "model\object.h"

Object::Object()
{

}

Object::Object(sf::Color color)
{
    this->color = color;
}

Object::~Object()
{
    delete shape;
}

sf::Shape *Object::getShape()
{
    return shape;
}

sf::Vector2f Object::getDirection(const Object &object1, const Object &object2)
{
    return calculateDirection(object1.shape->getPosition(), object2.shape->getPosition());
}

float Object::getDistance(const Object &object1, const Object &object2)
{
    return calculateDistance(object1.shape->getPosition(), object2.shape->getPosition());
}

float getGravitationalForce(const  Object &object2)
{
    return 0;
}

float Object::getMass() const
{
    return this->mass;
}

void Object::setColor(sf::Color color)
{
    this->color = color;
}

void Object::updatePosition(const double &deltaTime)
{
    shape->setPosition(shape->getPosition() + velocity * deltaTime);
}

void Object::updateVelocity(const double &deltaTime,const sf::Vector2f & force)
{
    velocity += force * deltaTime / mass;
}