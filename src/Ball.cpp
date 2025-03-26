#include "Ball.h"

Ball::Ball()
{
    body.setPosition(sf::Vector2f(util::window.width / 2 - m_ballRadius / 2, util::window.height / 2 - m_ballRadius / 2));
    body.setFillColor(sf::Color(255, 255, 0, 255));
    body.setRadius(m_ballRadius);
    m_left = true;
}

Ball::~Ball()
{
}

void Ball::movement(double deltaTime)
{
    sf::Vector2f ballMove(0.0f, 0.0f);
    ballMove.x += m_Xvel * deltaTime;
    ballMove.y += m_Yvel * deltaTime;
    body.move(ballMove);
}

void Ball::draw(sf::RenderWindow &window)
{
    window.draw(body);
}

void Ball::update(sf::RenderWindow &window, double deltaTime, std::vector<sf::FloatRect> colliders)
{
    collision(colliders);
    movement(deltaTime);
    draw(window);
}

void Ball::collision(std::vector<sf::FloatRect> colliders)
{
    float bodyLeft = body.getGlobalBounds().position.x;
    float bodyRight = body.getGlobalBounds().position.x + m_ballRadius + 30.0f;
    float bodyBottom = body.getGlobalBounds().position.y + m_ballRadius + 30.0f;
    float bodyUp = body.getGlobalBounds().position.y;

    for (sf::FloatRect &i : colliders)
    {
        float colliderLeft = i.position.x;
        float colliderRight = i.position.x + i.size.x;
        float colliderTop = i.position.y;
        float colliderBottom = i.position.y + i.size.y;

        if (bodyRight >= colliderLeft && bodyLeft <= colliderRight && bodyBottom >= colliderTop && bodyUp <= colliderBottom)
        {
            float overlapLeft = bodyRight - colliderLeft;
            float overlapRight = colliderRight - bodyLeft;
            float overlapTop = bodyBottom - colliderTop;
            float overlapBottom = colliderBottom - bodyUp;

            bool horizontalCollision = overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom ||
                                       overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom;
            if (horizontalCollision)
            {
                if (m_Xvel > 0)
                {
                    body.setPosition(sf::Vector2f(body.getPosition().x - overlapLeft, body.getPosition().y));
                }
                else
                {
                    body.setPosition(sf::Vector2f(body.getPosition().x + overlapRight, body.getPosition().y));
                }
                if (i.size.y == util::window.height && i.position.x < util::window.width / 2)
                {
                    m_TouchedRight = true;
                }
                else if (i.size.y == util::window.height && i.position.x > util::window.width / 2)
                {
                    m_TouchedLeft = true;
                }
                m_Xvel *= -1;
            }
            else
            {
                if (m_Yvel < 0)
                {
                    body.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y + overlapBottom));
                }
                else
                {
                    body.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y - overlapTop));
                }
                m_Yvel *= -1;
            }
        }
    }
}

void Ball::resetTouched()
{
    m_TouchedLeft = false;
    m_TouchedRight = false;
}

/* if (body.getGlobalBounds().findIntersection(i))
        {
            if (i.size.y != 300)
            {
                if (body.getGlobalBounds().position.x - 40 < 25)
                {
                    m_TouchedLeft = true;
                    m_Xvel *= -1;
                }
                if (body.getGlobalBounds().position.x + 75 > util::window.width - 25)
                {
                    m_TouchedRight = true;
                    m_Xvel *= -1;
                }
                if (body.getGlobalBounds().position.y - 40 < 125)
                {
                    m_Yvel *= -1;
                }
                if (body.getGlobalBounds().position.y + 75 > util::window.height - 25)
                {
                    m_Yvel *= -1;
                }
            }
            else
            {
                if (m_Xvel > 0)
                {
                    m_Yvel *= -1;
                }
                if (m_Yvel > 0)
                {
                    m_Xvel *= -1;
                }
            }
        } */