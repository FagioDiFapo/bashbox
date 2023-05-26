#include "model\gravitationalObject.h"

float GravitationalObject::getForce(const GravitationalObject &object1,const  Object &object2)
{
    return dlib::newton_G * object1.mass * object2.getMass() / std::pow(getDistance(object1, object2), 2);
}

void GravitationalObject::interact(const double &deltaTime, const Object &object2)
{
    sf::Vector2f forceVector = getForce(*this, object2) * getDirection(*this, object2);
    this->updateVelocity(deltaTime, forceVector);
}