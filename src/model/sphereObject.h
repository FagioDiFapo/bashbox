#ifndef SPHEREOBJECT_H
#define SPHEREOBJECT_H

#include <SFML\System.hpp>
#include "model\gravitationalObject.h"

class SphereObject : public GravitationalObject
{
public:
    SphereObject(sf::Vector2f position, sf::Vector2f velocity, float radius, float mass);

    float getRadius();

protected:
    float radius;
};

#endif