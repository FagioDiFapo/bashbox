#ifndef COLLIDABLEOBJECT_H
#define COLLIDABLEOBJECT_H

#include "model\object.h"

class CollidableObject : Object
{
public:
    virtual void interact(const double &deltaTime, const Object &object2) override;

private:
    float restitution;

};

#endif