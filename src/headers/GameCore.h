#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "SFML/Graphics.hpp"
#include "player.h"
#include "fieldLines.h"
#include "Ball.h"
#include "aiBot.h"
#include "ScoreBoard.h"
#include "Menu.h"


namespace GameCore
{
    void update(sf::RenderWindow &window, double &&deltaTime);
    void checkScore(int &num1,int &num2);
    void collisionManager();
    void mainFunc();
    void menuManager(sf::RenderWindow &window);
    void gameEnd(sf::RenderWindow &window,int &&player1Sco,int &&player2Sco);
} // namespace GameCore