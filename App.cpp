#include "App.hpp"

App::App()
{
    state = MENU;
    window.create(sf::VideoMode(800, 800), "Minesweeper");
    font.loadFromFile("resources/VT323-Regular.ttf");
    fontColor = sf::Color::Red;
    backColor = sf::Color(125, 125, 125);
}

void App::runApp()
{
    while (state != EXIT)
    {
        switch (state)
        {
        case MENU:
            menu();
            break;

        case GAME:
            play();
            break;

        default:
            break;
        }
    }
}

void App::menu()
{
    sf::Text title;
    title.setString("Minesweeper");
    title.setFont(font);
    title.setCharacterSize(50);
    title.setFillColor(fontColor);
    title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 50);

    sf::Text play;
    play.setString("Play");
    play.setFont(font);
    play.setCharacterSize(40);
    play.setFillColor(fontColor);
    play.setPosition(window.getSize().x / 2 - play.getGlobalBounds().width / 2, 150);

    sf::Text quit;
    quit.setString("Quit");
    quit.setFont(font);
    quit.setCharacterSize(40);
    quit.setFillColor(fontColor);
    quit.setPosition(window.getSize().x / 2 - quit.getGlobalBounds().width / 2, 250);

    while (state == MENU)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                state = EXIT;
                window.close();
                break;
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if (play.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                    state = GAME;
                    break;
                }
                if (quit.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                    state = EXIT;
                    window.close();
                    break;
                }
            }
        }

        window.clear(backColor);
        window.draw(title);
        window.draw(play);
        window.draw(quit);
        window.display();
    }
}

void App::play()
{
    while (true)
    {
        Game game(3);
        if (!game.runGame(window))
            break;
    }
    state = MENU;
}