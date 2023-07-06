#ifndef VIEW_H
#define VIEW_H

#include <SFML\Graphics.hpp>
#include "utils\utils.h"

class View
{
public:
    View(std::string applicationTitle, std::pair<int, int> windowResolution = std::pair(550, 450));
    ~View();

    bool initialize();
    void render();

    sf::Vector2f getAbsolutePosition(sf::Vector2f windowCoordinates);
    sf::Vector2f getMousePosition();

    void setShapes(const std::vector<sf::Drawable*> &shapes);
    void setSize(const sf::Vector2u size);
    void zoomView(float difference, sf::Vector2f target);
    void moveView(sf::Vector2f displacement);
    void closeWindow();

    bool isWindowOpen();
    bool windowPollEvent(sf::Event &event);

private:
    float viewZoom = 1.f;

    std::pair<int, int> windowResolution;
    std::string applicationTitle;

    sf::RenderWindow *window;
    sf::View view;
    std::vector<sf::Drawable*> shapes;
    //debug variables
    sf::CircleShape shape;

};

#endif