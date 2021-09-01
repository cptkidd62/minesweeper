#include "Game.hpp"

Game::Game()
{
    font.loadFromFile("resources/VT323-Regular.ttf");
    fontColor = sf::Color::Red;
    backColor = sf::Color(125, 125, 125);
    board = new Board(100, 100, 5, 2);
    state = PLAYING;
}

Game::~Game()
{
    delete board;
}

void Game::runGame(sf::RenderWindow &window)
{
    sf::Text timeTxt;
    timeTxt.setFont(font);
    timeTxt.setString("Time: 0:00");
    timeTxt.setCharacterSize(50);
    timeTxt.setPosition(50, 50);
    timeTxt.setFillColor(fontColor);

    sf::Clock timer;

    std::pair<int, int> p = board->click(sf::Vector2f(0, 0), true);

    sf::Text bombTxt;
    bombTxt.setFont(font);
    bombTxt.setString("Bombs: " + std::to_string(p.first));
    bombTxt.setCharacterSize(50);
    bombTxt.setPosition(50, 150);
    bombTxt.setFillColor(fontColor);

    sf::Text menuBtn;
    menuBtn.setFont(font);
    menuBtn.setString("Menu");
    menuBtn.setCharacterSize(50);
    menuBtn.setPosition(50, 700);
    menuBtn.setFillColor(fontColor);

    sf::Text replayBtn;
    replayBtn.setFont(font);
    replayBtn.setString("New Game");
    replayBtn.setCharacterSize(50);
    replayBtn.setPosition(350, 700);
    replayBtn.setFillColor(fontColor);

    timer.restart();

    while (state == PLAYING || state == LOST)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
            {
                state = EXIT;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (menuBtn.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        state = EXIT;
                    }
                    else if (replayBtn.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && state == LOST)
                    {
                        //TODO
                    }
                    else if (state == PLAYING)
                    {
                        p = board->click(window.mapPixelToCoords(sf::Mouse::getPosition(window)), true);
                        bombTxt.setString("Bombs: " + std::to_string(p.first));
                        if (p.second < 0)
                        {
                            state = LOST;
                        };
                        if (p.second == 0)
                        {
                            state = WON;
                        };
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Right && state == PLAYING)
                {
                    p = board->click(window.mapPixelToCoords(sf::Mouse::getPosition(window)), false);
                    bombTxt.setString("Bombs: " + std::to_string(p.first));
                    if (p.second < 0)
                    {
                        state = LOST;
                    };
                    if (p.second == 0)
                    {
                        state = WON;
                    };
                }
            }
        }

        if (state == PLAYING)
        {
            int snap = timer.getElapsedTime().asSeconds();
            timeTxt.setString("Time: " + std::to_string(snap / 60) + (snap % 60 < 10 ? ":0" : ":") + std::to_string(snap % 60));
        }

        window.clear(backColor);
        window.draw(timeTxt);
        window.draw(bombTxt);
        window.draw(menuBtn);
        if (state == LOST)
            window.draw(replayBtn);
        window.draw(*board);
        window.display();
    }
}