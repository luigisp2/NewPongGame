#include "fieldLines.h"

FieldLines::FieldLines()
{   
    /* Set the green lines in the field */
    m_lines.at(0).setSize(sf::Vector2f(util::window.width,25));
    m_lines.at(0).setPosition(sf::Vector2f(0.0f,100.0f));
    m_lines.at(0).setFillColor(sf::Color::Green);

    m_lines.at(1).setSize(sf::Vector2f(util::window.width,25));
    m_lines.at(1).setPosition(sf::Vector2f(0.0f,util::window.height-25));
    m_lines.at(1).setFillColor(sf::Color::Green);

    m_lines.at(2).setSize(sf::Vector2f(25,util::window.height));
    m_lines.at(2).setPosition(sf::Vector2f(0.0f,100.0f));
    m_lines.at(2).setFillColor(sf::Color::Green);

    m_lines.at(3).setSize(sf::Vector2f(25,util::window.height));
    m_lines.at(3).setPosition(sf::Vector2f(util::window.width-25,100.0f));
    m_lines.at(3).setFillColor(sf::Color::Green);

    m_centerLine.setSize(sf::Vector2f(10,util::window.height));
    m_centerLine.setPosition(sf::Vector2f((util::window.width/2)-5,100.0f));
    m_centerLine.setFillColor(sf::Color::Green);

    /* Sets the big green circle in the center of the field */
    m_centerCircle.setRadius(150.0f);
    m_centerCircle.setPosition(sf::Vector2f((util::window.width/2)-150,(util::window.height/2)-150));
    m_centerCircle.setFillColor(sf::Color::Black);
    m_centerCircle.setOutlineColor(sf::Color::Green);
    m_centerCircle.setOutlineThickness(10.0f);
}

FieldLines::~FieldLines()
{
}

/* Function that tells the window to draw the lines and circle */
void FieldLines::Draw(sf::RenderWindow &window)
{   
    window.draw(m_centerLine);
    window.draw(m_centerCircle);
    for (sf::RectangleShape &i : m_lines) window.draw(i);
}
