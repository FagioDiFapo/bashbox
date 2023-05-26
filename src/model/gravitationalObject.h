#ifndef GRAVITATIONALOBJECT_H
#define GRAVITATIONALOBJECT_H

#include "model\object.h"
#include "utils\dlib.h"

class GravitationalObject : public Object
{
public:
    static float getForce(const GravitationalObject &object1,const  Object &object2);
    virtual void interact(const double &deltaTime, const Object &object2) override;

};

#endif