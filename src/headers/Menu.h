#pragma once
#include "iostream"
#include "SFML/Graphics.hpp"
#include "utils.h"
#include <chrono>
class Menu
{

public:
    Menu(/* args */);
    ~Menu();
    void draw(sf::RenderWindow &window);
    void buttonClick(sf::RenderWindow &window);
    bool get_isButtonClicked(){return m_PlayButtonCliked;}

    int get_ButtonClickedType(){return m_WhichButtonClicked;}

private:

    bool m_PlayButtonCliked{false};
    int m_WhichButtonClicked{0};

    sf::Font m_Font{"vertopal.com_8514OEM.ttf"};
    sf::Text m_GameTitle{m_Font};
    sf::Text m_PlayButton{m_Font};
    sf::Text m_PlayWith2Text{m_Font};
    sf::Text m_MiniTutorial{m_Font};
};
