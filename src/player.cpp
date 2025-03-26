#include "player.h"

Player::Player()
{
    //Setting up the Player characteristics
    std::cout << "Initiating Player" << "\n";
    body.setFillColor(sf::Color::White);
    body.setSize(sf::Vector2f(50,300));
    body.setPosition(sf::Vector2f(50,util::window.height/2-150));
}

Player::~Player()
{
    std::cout << "getting destroyed" << std::endl;
}

void Player::movement(double deltaTime)
{
    sf::Vector2 move(0.0f,0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) move.y -= m_speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) move.y += m_speed * deltaTime;
/*     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) move.x -= m_speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) move.x += m_speed * deltaTime; */
    collision();
    body.move(move);
}

void Player::Draw(sf::RenderWindow &window)
{
    window.draw(body);
}

void Player::Update(sf::RenderWindow &window,double deltaTime)
{
    Draw(window);
    movement(deltaTime);
}

void Player::collision()
{
    if (body.getGlobalBounds().position.y < m_upperBound)
    {
        body.setPosition(sf::Vector2f(body.getPosition().x,125));
    }
    if ((body.getGlobalBounds().position.y + 300) > m_lowerBound)
    {
        body.setPosition(sf::Vector2f(body.getPosition().x,util::window.height-325));
    }
    
}
