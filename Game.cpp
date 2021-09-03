#include "Game.hpp"

Game::Game(int level)
{
    font.loadFromFile("resources/VT323-Regular.ttf");
    fontColor = sf::Color::Red;
    backColor = sf::Color(125, 125, 125);
    if (level == 1)
    {
        board = new Board(40, 70, 5, 5);
    }
    else if (level == 2)
    {
        board = new Board(40, 70, 7, 10);
    }
    else if (level == 3)
    {
        board = new Board(40, 70, 10, 20);
    }
    state = PLAYING;
}

Game::~Game()
{
    delete board;
}

int Game::runGame(sf::RenderWindow &window)
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
    bombTxt.setPosition(350, 50);
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

    int winTime;

    while (state == PLAYING || state == LOST)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                state = EXIT;
                return -1;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
            {
                state = MENU;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (menuBtn.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                    {
                        state = MENU;
                        return 0;
                    }
                    else if (replayBtn.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && state == LOST)
                    {
                        state = REPLAY;
                        return 1;
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
                            winTime = timer.getElapsedTime().asSeconds();
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

    // string for user name
    sf::String str(L"");

    // texts
    sf::Text title;
    title.setFont(font);
    title.setCharacterSize(40);
    title.setFillColor(fontColor);
    title.setString("You won with time " + std::to_string(winTime / 60) + (winTime % 60 < 10 ? ":0" : ":") + std::to_string(winTime % 60) + "\nType your name:");
    title.setPosition(100, 100);

    sf::Text name;
    name.setFont(font);
    name.setCharacterSize(40);
    name.setFillColor(fontColor);
    name.setString(str);
    name.setPosition(100, 300);

    sf::Text confirm;
    confirm.setFont(font);
    confirm.setCharacterSize(40);
    confirm.setFillColor(fontColor);
    confirm.setString("Confirm");
    confirm.setPosition(100, 400);

    while (state == WON)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // if string !empty save score
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter && !str.isEmpty())
            {
                return 0;
            }
            // enter text
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode >= 32 && event.text.unicode <= 383)
                {
                    str.insert(str.getSize(), static_cast<wchar_t>(event.text.unicode));
                }
                // backspace
                if (event.text.unicode == 8)
                {
                    if (str.getSize() > 0)
                    {
                        str.erase(str.getSize() - 1, 1);
                    }
                }
                name.setString(str);
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                // if string !empty save score
                if (confirm.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))) && !str.isEmpty())
                {
                    return 0;
                }
            }
        }

        window.clear(backColor);
        window.draw(title);
        window.draw(name);
        window.draw(confirm);
        window.display();
    }
    return 0;
}