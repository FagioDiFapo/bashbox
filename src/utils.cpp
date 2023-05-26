#include "utils\utils.h"

sf::Vector2f operator*(sf::Vector2f vector, float value)
{
    return sf::Vector2f(vector.x * value, vector.y * value);
}

sf::Vector2f calculateVector(sf::Vector2f point1, sf::Vector2f point2)
{
    return sf::Vector2f(point2.x - point1.x, point2.y - point1.y);
}

sf::Vector2f calculateDirection(sf::Vector2f point1, sf::Vector2f point2)
{
    return calculateVector(point1, point2)/calculateDistance(point1, point2);
}

float calculateDistance(sf::Vector2f point1, sf::Vector2f point2)
{
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}