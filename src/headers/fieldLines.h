#pragma once
#include <iostream>
#include <array>
#include "SFML/Graphics.hpp"
#include "utils.h"

class FieldLines
{

public:
    FieldLines();
    ~FieldLines();
    void Draw(sf::RenderWindow &window);

    std::array<sf::RectangleShape,4> get_colliders(){return m_lines;}
private:
    //Array that is going to store the white lines that is going to be drawn on the map
    std::array<sf::RectangleShape,4> m_lines;
    sf::RectangleShape m_centerLine;
    sf::CircleShape m_centerCircle;

};
