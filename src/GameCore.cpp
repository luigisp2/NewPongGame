#include "GameCore.h"

std::vector<sf::FloatRect> colliders;
Player plr1;
AiBot bot;
Ball gameBall;
FieldLines lines;
ScoreBoard gameBoard;

void GameCore::update(sf::RenderWindow &window, double &&deltaTime)
{
    collisionManager();
    lines.Draw(window);
    plr1.Update(window, deltaTime);
    bot.update(window, deltaTime, gameBall.getPos().y, gameBall.getPos().x);
    gameBall.update(window, deltaTime, colliders);
    gameBoard.draw(window);
    colliders.clear();
}

void GameCore::checkScore(int &num1, int &num2)
{
    if (gameBall.goalTouchedLeft())
    {
        num2 += 1;
        gameBoard.set_PlayerScore(num2);
        gameBall.resetTouched();
    }
    if (gameBall.goalTouchedRight())
    {
        num1 += 1;
        gameBoard.set_EnemyScore(num1);
        gameBall.resetTouched();
    }
}

void GameCore::collisionManager()
{
    for (auto &i : lines.get_colliders())
    {
        colliders.push_back(i.getGlobalBounds());
    }
    colliders.push_back(bot.get_collider());
    colliders.push_back(plr1.get_collider());
}

void GameCore::mainFunc()
{
    sf::RenderWindow window(sf::VideoMode({util::window.width, util::window.height}), "PongGame");
    GameCore::menuManager(window);

    int gameTimerCount{5};
    int accountant{0};
    int playerScore{0}, enemyScore{0};
    double deltaTime{0.0f};

    sf::Clock clockFor_DeltaT;
    sf::Clock gameTimer;

    while (window.isOpen())
    {
        if (std::floor(gameTimer.getElapsedTime().asSeconds()) > accountant)
        {
            gameTimerCount -= 1;
            accountant += 1;
            gameBoard.set_TimerCountDown(gameTimerCount);
            if (gameTimerCount <= 0)
            {   
                gameBoard.set_TimerCountDown(gameTimerCount);
                GameCore::gameEnd(window,std::move(playerScore),std::move(enemyScore));
            }
        }
        deltaTime = clockFor_DeltaT.restart().asSeconds();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear();
        GameCore::update(window, std::move(deltaTime));
        GameCore::checkScore(enemyScore, playerScore);
        window.display();
    }
}

void GameCore::menuManager(sf::RenderWindow &window)
{
    Menu gameMenu;
    sf::Clock waittime;
    bool begin{true};
    while (window.isOpen())
    {
        if (gameMenu.get_isButtonClicked())
        {
            if (begin)
            {
                begin = false;
                waittime.restart();
            }

            if (waittime.getElapsedTime().asMilliseconds() >= 300)
            {
                bot.setPlayChoice(gameMenu.get_ButtonClickedType());
                break;
            }
        }
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear();
        gameMenu.draw(window);
        window.display();
    }
}

void GameCore::gameEnd(sf::RenderWindow &window,int &&player1Sco,int &&player2Sco)
{   
    bool begin{true};
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        if (begin)
        {   
            gameBoard.drawWinMessage(window,std::move(player1Sco),std::move(player2Sco));
            window.display();
            begin = false;
        }
    }
    
}
