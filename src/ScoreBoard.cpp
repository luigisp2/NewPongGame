#include "ScoreBoard.h"

ScoreBoard::ScoreBoard()
{   
    m_PlayerScore.setPosition(sf::Vector2f(900.0f,0.0f));
    m_PlayerScore.setCharacterSize(75);
    m_PlayerScore.setString("0");

    m_EnemyScore.setPosition(sf::Vector2f(1050,0.0f));
    m_EnemyScore.setCharacterSize(75);
    m_EnemyScore.setString("0");

    m_TimerCountDown.setPosition(sf::Vector2f(util::window.width - 450.0f,0.0f));
    m_TimerCountDown.setCharacterSize(50);
    m_TimerCountDown.setString("time left: 300");

    m_EnemyWon.setCharacterSize(100);
    m_EnemyWon.setPosition(sf::Vector2f(util::window.widthBy2 - 400,util::window.heighBy2 + 450));
    m_EnemyWon.setString("Player 2 WON!");

    m_PlayerWon.setCharacterSize(100);
    m_PlayerWon.setPosition(sf::Vector2f(util::window.widthBy2 - 400,util::window.heighBy2 + 450));
    m_PlayerWon.setString("Player 1 WON!");
}

ScoreBoard::~ScoreBoard()
{

}

void ScoreBoard::draw(sf::RenderWindow &window)
{
    window.draw(m_TimerCountDown);
    window.draw(m_EnemyScore);
    window.draw(m_PlayerScore);
}

void ScoreBoard::drawWinMessage(sf::RenderWindow &window,int &&plr1, int &&plr2)
{
    if (plr1 > plr2)
    {
        window.draw(m_PlayerWon);
    }else
    {
        window.draw(m_EnemyWon);
    }
    
}
