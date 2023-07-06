#include "view\view.h"

View::View(std::string applicationTitle, std::pair<int, int> windowResolution)
{
    this->windowResolution = windowResolution;
    this->applicationTitle = applicationTitle;
    //debug initialization
    shape = sf::CircleShape(100.f);
    shape.setFillColor(sf::Color::Cyan);
}

View::~View()
{

}

bool View::initialize()
{
    window = new sf::RenderWindow(sf::VideoMode(windowResolution.first, windowResolution.second), applicationTitle);
    if (window == NULL) return false;
    view = sf::View(sf::Vector2f(windowResolution.first/2,windowResolution.second/2), sf::Vector2f(windowResolution.first,windowResolution.second));
    window->setView(view);
    return true;
}

//Outdated render function
void View::render()
{
    window->clear();
    for (int i = 0; i < shapes.size(); ++i)
    {
        window->draw(*shapes[i]);
    }
    window->display();
}

sf::Vector2f View::getAbsolutePosition(sf::Vector2f windowCoordinates)
{
    sf::Vector2f pointWindowPosition = windowCoordinates;
    sf::Vector2f pointViewPosition = pointWindowPosition / (sf::Vector2f)window->getSize() * view.getSize();
    sf::Vector2f viewPosition = view.getCenter() - view.getSize() / 2.f;
    return viewPosition + pointViewPosition;
}

sf::Vector2f View::getMousePosition()
{
    sf::Vector2i integerMousePosition = sf::Mouse::getPosition(*window);
    return static_cast<sf::Vector2f>(integerMousePosition);
}

void View::setShapes(const std::vector<sf::Drawable*> &shapes)
{
    this->shapes = shapes;
}

void View::setSize(const sf::Vector2u size)
{
    window->setSize(size);
    view.setSize(static_cast<float>(size.x), static_cast<float>(size.y));
    window->setView(view);
}

void View::zoomView(float difference, sf::Vector2f target)
{
    float newZoom = viewZoom + 0.5 * difference * viewZoom;
    if (newZoom > 0)
    {
        sf::Vector2f targetPositionBefore = getAbsolutePosition(target);
        view.zoom(1/viewZoom);
        viewZoom = newZoom;
        view.zoom(viewZoom);
        sf::Vector2f targetPositionAfter = getAbsolutePosition(target);
        sf::Vector2f deltaTarget = (targetPositionAfter - targetPositionBefore);
        view.move(-deltaTarget);
        window->setView(view);
    }
}

void View::moveView(sf::Vector2f displacement)
{
    view.move(displacement * viewZoom);
    window->setView(view);
}

void View::closeWindow()
{
    window->close();
}

bool View::isWindowOpen()
{
    return window->isOpen();
}

bool View::windowPollEvent(sf::Event &event)
{
    return window->pollEvent(event);
}