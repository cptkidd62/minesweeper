#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Game.hpp"

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
        GAME,
        SCORES
    };
    AppState state;
    sf::RenderWindow window;
    sf::Font font;
    sf::Color fontColor, backColor;

    void menu();
    void play();
    void scores();
};

#endif