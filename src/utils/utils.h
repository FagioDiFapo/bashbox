#ifndef UTILS_H
#define UTILS_H

#include <SFML\System.hpp>
#include <cmath>

sf::Vector2f operator*(sf::Vector2f vector, float value);

sf::Vector2f operator*(sf::Vector2f vector1, sf::Vector2f vector2);

sf::Vector2f operator/(sf::Vector2f vector1, sf::Vector2f vector2);

sf::Vector2f calculateDirection(sf::Vector2f point1, sf::Vector2f point2);

float calculateDistance(sf::Vector2f point1, sf::Vector2f point2);

#endif