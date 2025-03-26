#include "Menu.h"

Menu::Menu()
{
    m_GameTitle.setString("Pong Game");
    m_GameTitle.setCharacterSize(110);
    m_GameTitle.setPosition(sf::Vector2f(util::window.widthBy2 - m_GameTitle.getGlobalBounds().size.x / 2,100));

    m_PlayButton.setString("Play");
    m_PlayButton.setCharacterSize(90);
    m_PlayButton.setPosition(sf::Vector2f(util::window.widthBy2 - m_PlayButton.getGlobalBounds().size.x / 2,600));

    m_PlayWith2Text.setString("Play - 2 players");
    m_PlayWith2Text.setCharacterSize(90);
    m_PlayWith2Text.setPosition(sf::Vector2f(util::window.widthBy2 - m_PlayWith2Text.getGlobalBounds().size.x / 2,900));

    m_MiniTutorial.setString("Player 1 movement: W & S \n \nPlayer 2 movement: UpKey & DownKey");
    m_MiniTutorial.setCharacterSize(50);
    m_MiniTutorial.setPosition(sf::Vector2f(m_PlayWith2Text.getGlobalBounds().position.x,1200));
    m_MiniTutorial.setFillColor(sf::Color::Transparent);
}

Menu::~Menu()
{
    std::cout << "Getting Destroyed1213";
}

void Menu::draw(sf::RenderWindow &window)
{
    buttonClick(window);
    window.draw(m_MiniTutorial);
    window.draw(m_PlayWith2Text);
    window.draw(m_PlayButton);
    window.draw(m_GameTitle);
}

void Menu::buttonClick(sf::RenderWindow &window)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        if (sf::Mouse::getPosition(window).x >= m_PlayButton.getGlobalBounds().position.x 
        && sf::Mouse::getPosition(window).x <= m_PlayButton.getGlobalBounds().position.x + m_PlayButton.getGlobalBounds().size.x
        && sf::Mouse::getPosition(window).y >= m_PlayButton.getGlobalBounds().position.y
        &&  sf::Mouse::getPosition(window).y <= m_PlayButton.getGlobalBounds().position.y + m_PlayButton.getGlobalBounds().size.y)
        {   
            m_WhichButtonClicked = 0;
            m_PlayButtonCliked = true;
            m_PlayButton.setFillColor(sf::Color::Red);
        }
    }
    

    if (sf::Mouse::getPosition(window).x >= m_PlayWith2Text.getGlobalBounds().position.x 
    && sf::Mouse::getPosition(window).x <= m_PlayWith2Text.getGlobalBounds().position.x + m_PlayWith2Text.getGlobalBounds().size.x
    && sf::Mouse::getPosition(window).y >= m_PlayWith2Text.getGlobalBounds().position.y
    &&  sf::Mouse::getPosition(window).y <= m_PlayWith2Text.getGlobalBounds().position.y + m_PlayWith2Text.getGlobalBounds().size.y)
    {
        m_MiniTutorial.setFillColor(sf::Color::White);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {   
            m_WhichButtonClicked = 1;
            m_PlayButtonCliked = true;
            m_PlayWith2Text.setFillColor(sf::Color::Red);
        }
    }else
    {
        m_MiniTutorial.setFillColor(sf::Color::Transparent);
    }
}
