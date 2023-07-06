#include "controller\controller.h"

Controller::Controller(std::pair<int, int> viewWindowResolution)
{
    this->viewWindowResolution = viewWindowResolution;
    clock = sf::Clock();
    view = new View(applicationTitle, this->viewWindowResolution);
    model = new Model();
}

Controller::Controller()
{
    clock = sf::Clock();
    view = new View(applicationTitle);
    model = new Model();
}

Controller::~Controller()
{
    close();
}

bool Controller::initialize()
{
    bool response = true;
    clock.restart();
    response &= model->initialize();
    response &= view->initialize();
    view->setShapes(model->getShapes());
    return response;
}

void Controller::run()
{
    float deltaTime = clock.restart().asSeconds();
    while (view->isWindowOpen())
    {
        handleEvents();
        handleModel(deltaTime);
        handleView();
    }
}

void Controller::handleKeyPress(const sf::Event &event)
{
    switch (event.key.code)
    {
        case sf::Keyboard::LControl:
            heldLControl = true;
            break;
        default:
            break;
    }
}

void Controller::handleKeyRelease(const sf::Event &event)
{
    switch (event.key.code)
    {
        case sf::Keyboard::LControl:
            heldLControl = false;
            break;
        default:
            break;
    }
}

void Controller::handleMouseMove(const sf::Event &event)
{
    sf::Vector2f mouseDisplacement = view->getMousePosition() - lastMousePosition;
    lastMousePosition = view->getMousePosition();
    if (heldMouse) {
        if (heldLControl)
        {

        }
        else
        {
            view->moveView(-mouseDisplacement);
        }
    }
}

void Controller::handleMouseScroll(const sf::Event &event)
{
    if (heldLControl) model->updateSimulationSpeed(event.mouseWheelScroll.delta);
    else view->zoomView(-event.mouseWheelScroll.delta, view->getMousePosition());
}

void Controller::handleEvents()
{
    sf::Event event;
    while (view->windowPollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                view->closeWindow();
                break;
            case sf::Event::Resized:
                view->setSize(sf::Vector2u(event.size.width, event.size.height));
                break;
            case sf::Event::MouseWheelScrolled:
                handleMouseScroll(event);
                break;
            case sf::Event::MouseButtonPressed:
                heldMouse = true;
                lastMousePosition = view->getMousePosition();
                break;
            case sf::Event::MouseButtonReleased:
                heldMouse = false;
                break;
            case sf::Event::MouseMoved:
                handleMouseMove(event);
            case sf::Event::KeyPressed:
                handleKeyPress(event);
                break;
            case sf::Event::KeyReleased:
                handleKeyRelease(event);
                break;
            default:
                break;
        }

    }
}

void Controller::handleModel(float deltaTime)
{
    model->update(deltaTime);
}

void Controller::handleView()
{
    view->render();
}

void Controller::close()
{
    //view->~View();
    delete view;
    delete model;
}