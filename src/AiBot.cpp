#include "AiBot.h"

AiBot::AiBot()
{
    m_body.setSize(sf::Vector2f(50.0f, 300.0f));
    m_body.setPosition(sf::Vector2f(util::window.width - 100, util::window.height / 2 - 150));
}

AiBot::~AiBot()
{
}

void AiBot::draw(sf::RenderWindow &window)
{
    window.draw(m_body);
}

void AiBot::movement(float deltaTime, int target_Ypos, int target_Xpos)
{
    sf::Vector2f bodyMover;
    if (m_playChoice == type1)
    {
        if (target_Xpos > util::window.width / 2)
        {
            if (m_body.getPosition().y + m_body.getGlobalBounds().size.y  /2  > target_Ypos)
            {
                bodyMover.y -= m_speed * deltaTime;
            }
            else
            {
                bodyMover.y += m_speed * deltaTime;
            }
        }
    }else if (m_playChoice == type2)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) bodyMover.y -= m_speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) bodyMover.y += m_speed * deltaTime;
    }
    collision();
    m_body.move(sf::Vector2f(0,bodyMover.y));
}

void AiBot::update(sf::RenderWindow &window, float deltaTime, int target_Ypos, int target_Xpos)
{
    movement(deltaTime,target_Ypos,target_Xpos);
    draw(window);
}

void AiBot::collision()
{
    if (m_body.getGlobalBounds().position.y  < m_upperBound)
    {
        m_body.setPosition(sf::Vector2f(m_body.getPosition().x,125));
    }
    if ((m_body.getGlobalBounds().position.y + 300) > m_lowerBound)
    {
        m_body.setPosition(sf::Vector2f(m_body.getPosition().x,util::window.height-325));
    }
}

void AiBot::setPlayChoice(int choice)
{
    switch (choice)
    {
    case 0:
        m_playChoice = type1;
        break;
    case 1:
        m_playChoice = type2;
        break;
    default:
        break;
    }
}
