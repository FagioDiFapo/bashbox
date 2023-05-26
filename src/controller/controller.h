#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view\view.h"
#include "model\model.h"

class Controller
{
public:
    Controller(std::pair<int, int> viewWindowResolution);
    Controller();
    ~Controller();

    bool initialize();
    void run();
    void handleKeyPress(const sf::Event &event);
    void handleKeyRelease(const sf::Event &event);
    void handleMouseMove(const sf::Event &event);
    void handleMouseScroll(const sf::Event &event);
    void handleEvents();
    void handleModel(float deltaTime);
    void handleView();

private:
    View *view;
    Model *model;

    sf::Clock clock;
    std::string applicationTitle = "Bashbox";
    std::pair<int, int> viewWindowResolution;
    bool heldMouse = false;
    bool heldLControl = false;
    sf::Vector2f lastMousePosition;

    void close();

};

#endif