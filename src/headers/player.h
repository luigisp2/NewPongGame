#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "utils.h"
/* Player class */
class Player
{

public:
    Player();
    ~Player();
    void movement(double deltaTime);
    void Draw(sf::RenderWindow &window);
    void Update(sf::RenderWindow &window,double deltaTime);
    void collision();

    sf::FloatRect get_collider(){return body.getGlobalBounds();}


private:
    /* player speed */
    const float m_speed{550.0f};
    /* Max and Min height the player can go */
    const unsigned int m_upperBound{125},m_lowerBound{util::window.height-25};
    
    sf::RectangleShape body;
};
