#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>

class App
{
public:
    App();

    void runApp();

private:
    enum AppState
    {
        EXIT,
        MENU,
        GAME
    };
    AppState state;
    sf::RenderWindow window;
    sf::Font font;
    sf::Color fontColor, backColor;

    void menu();
};

#endif