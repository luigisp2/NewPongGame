#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "utils.h"

class ScoreBoard
{
public:
    ScoreBoard(/* args */);
    ~ScoreBoard();
    void draw(sf::RenderWindow &window);

    void set_PlayerScore(int &num){m_PlayerScore.setString(std::to_string(num));}
    void set_EnemyScore(int &num){m_EnemyScore.setString(std::to_string(num));}
    void set_TimerCountDown(int &num){m_TimerCountDown.setString("Time left: " + std::to_string(num));}

    void drawWinMessage(sf::RenderWindow &window,int &&plr1, int &&plr2);

private:
    sf::Font m_Font{"vertopal.com_8514OEM.ttf"};
    sf::Text m_EnemyScore{m_Font};
    sf::Text m_PlayerScore{m_Font};

    sf::Text m_PlayerWon{m_Font};
    sf::Text m_EnemyWon{m_Font};

    sf::Text m_TimerCountDown{m_Font};
};
