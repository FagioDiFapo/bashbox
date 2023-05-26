#ifndef VIEW_H
#define VIEW_H

#include <SFML\Graphics.hpp>

class View
{
public:
    View(std::string applicationTitle, std::pair<int, int> windowResolution = std::pair(550, 450));
    ~View();

    bool initialize();
    void render();
    void setShapes(const std::vector<sf::Drawable*> &shapes);
    void setSize(const sf::Vector2u size);
    void zoomView(float difference);
    void moveView(sf::Vector2f displacement);
    void closeWindow();

    bool isWindowOpen();
    bool windowPollEvent(sf::Event &event);
    sf::Vector2f getMousePosition();

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