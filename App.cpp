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
        }
        
        window.clear(backColor);
        window.draw(title);
        window.display();
    }
}