#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "utils.h"

class Ball
{
public:
    Ball(/* args */);
    ~Ball();
    
    void movement(double deltaTime);
    void draw(sf::RenderWindow &window);
    void update(sf::RenderWindow &window, double deltaTime, std::vector<sf::FloatRect> colliders);
    void collision(std::vector<sf::FloatRect> colliders);

    bool goalTouchedRight() {return m_TouchedRight;}
    bool goalTouchedLeft() {return m_TouchedLeft;}

    void resetTouched();

    sf::Vector2f getPos() {return body.getPosition();}
private:
    sf::CircleShape body;
    int m_Yvel{800},m_Xvel{800};
    
    float m_ballRadius{40.0f};

    bool m_up{false},m_down{false},m_right{false},m_left{false};
    bool m_TouchedRight{false},m_TouchedLeft{false};
};
