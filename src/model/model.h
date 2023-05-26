#ifndef MODEL_H
#define MODEL_H

#include <SFML\Graphics.hpp>
#include "model\object.h"
#include "model\gravitationalObject.h"
#include "model\sphereObject.h"

class Model
{
public:
    Model();
    bool initialize();

    void update(float deltaTime);
    void updateSimulationSpeed(float difference);
    std::vector<sf::Drawable*> getShapes();

private:
    std::vector<Object*> objects;
    std::vector<sf::Drawable*> shapes;
    float simulationSpeed = 1;

};

#endif