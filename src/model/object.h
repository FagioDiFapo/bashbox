#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics.hpp>
#include "utils\utils.h"

class Object
{
public:
    Object();
    Object(sf::Color color);
    ~Object();

    sf::Shape *getShape();
    static sf::Vector2f getDirection(const Object &object1, const Object &object2);
    static float getDistance(const Object &object1,const  Object &object2);
    //float getGravitationalForce(const  Object &object2);
    float getMass() const;

    virtual void interact(const double &deltaTime, const Object &object2) = 0;
    void setColor(sf::Color color);
    void updatePosition(const double &deltaTime);
    void updateVelocity(const double &deltaTime, const sf::Vector2f &acceleration);

    //void render(const sf::Window& window);

protected:
    sf::Shape *shape;
    sf::Color color;
    sf::Vector2f velocity;
    float mass = 1;
    float angularVelocity;
};

#endif