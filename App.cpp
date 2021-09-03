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
    sf::Text easy;
    easy.setString("Easy");
    easy.setFont(font);
    easy.setCharacterSize(40);
    easy.setFillColor(fontColor);
    easy.setPosition(window.getSize().x / 2 - easy.getGlobalBounds().width / 2, 50);

    sf::Text medium;
    medium.setString("Medium");
    medium.setFont(font);
    medium.setCharacterSize(40);
    medium.setFillColor(fontColor);
    medium.setPosition(window.getSize().x / 2 - medium.getGlobalBounds().width / 2, 150);

    sf::Text hard;
    hard.setString("Hard");
    hard.setFont(font);
    hard.setCharacterSize(40);
    hard.setFillColor(fontColor);
    hard.setPosition(window.getSize().x / 2 - hard.getGlobalBounds().width / 2, 250);

    sf::Text back;
    back.setString("Menu");
    back.setFont(font);
    back.setCharacterSize(40);
    back.setFillColor(fontColor);
    back.setPosition(window.getSize().x / 2 - back.getGlobalBounds().width / 2, 350);

    while (state == GAME)
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
                if (easy.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                    while (state == GAME)
                    {
                        Game game(1);
                        switch (game.runGame(window))
                        {
                        case 0:
                            state = MENU;
                            break;

                        case -1:
                            state = EXIT;
                            break;

                        default:
                            break;
                        }
                    }
                    break;
                }
                if (medium.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                    while (state == GAME)
                    {
                        Game game(2);
                        switch (game.runGame(window))
                        {
                        case 0:
                            state = MENU;
                            break;

                        case -1:
                            state = EXIT;
                            break;

                        default:
                            break;
                        }
                    }
                    break;
                }
                if (hard.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                    while (state == GAME)
                    {
                        Game game(3);
                        switch (game.runGame(window))
                        {
                        case 0:
                            state = MENU;
                            break;

                        case -1:
                            state = EXIT;
                            break;

                        default:
                            break;
                        }
                    }
                    break;
                }
                if (back.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
                {
                    state = MENU;
                    break;
                }
            }
        }

        window.clear(backColor);
        window.draw(easy);
        window.draw(medium);
        window.draw(hard);
        window.draw(back);
        window.display();
    }
}