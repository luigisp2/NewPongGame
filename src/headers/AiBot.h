#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "utils.h"

class AiBot
{

public:
    AiBot();
    ~AiBot();
    void draw(sf::RenderWindow &window);
    void movement(float deltaTime, int target_Ypos, int target_Xpos);
    void update(sf::RenderWindow &window, float deltaTime, int target_Ypos, int target_Xpos);
    void collision();

    void setPlayChoice(int choice);
    sf::FloatRect get_collider() { return m_body.getGlobalBounds(); }

private:
    const float m_speed{550.0f};
    const unsigned int m_upperBound{125}, m_lowerBound{util::window.height - 25};
    enum m_PlayType {type1,type2} m_playChoice;
    sf::RectangleShape m_body;
};
