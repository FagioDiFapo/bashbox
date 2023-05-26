#include "model\model.h"

Model::Model()
{
    std::vector<Object*> objects = std::vector<Object*>(3);
    objects[0] = new SphereObject(sf::Vector2f(100.f, 100.f), sf::Vector2f(-0.00005f, -0.0000375f), 20.f, 20000.f);
    objects[1] = new SphereObject(sf::Vector2f(100.f, 150.f), sf::Vector2f(0.0001f, 0.00005f), 10.f, 10000.f);
    objects[2] = new SphereObject(sf::Vector2f(170.f, 150.f), sf::Vector2f(0.f, 0.00005f), 10.f, 5000.f);

    this->objects = std::vector<Object*>(objects.size());
    for (int i = 0; i < objects.size(); ++i)
    {
        this->objects[i] = objects[i];
    }
}

bool Model::initialize()
{
    shapes = std::vector<sf::Drawable*>(objects.size());
    for (int i = 0; i < objects.size(); ++i)
    {
        shapes[i] = objects[i]->getShape();
    }
    return true;
}

void Model::update(float deltaTime)
{
    deltaTime *= simulationSpeed;
    for (int i = 0; i < objects.size(); ++i)
    {
        Object *object1 = objects[i];
        object1->updatePosition(deltaTime);
        for (int j = i+1; j < objects.size(); ++j)
        {
            Object *object2 = objects[j];
            object2->updatePosition(deltaTime);
            object1->interact(deltaTime, *object2);
            object2->interact(deltaTime, *object1);
        }
    }
}

void Model::updateSimulationSpeed(float difference)
{
    simulationSpeed += difference;
}

std::vector<sf::Drawable*> Model::getShapes()
{
    return shapes;
}