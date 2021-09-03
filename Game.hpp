#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <fstream>
#include "Board.hpp"

class Game
{
public:
    Game(int level);
    ~Game();

    int runGame(sf::RenderWindow &window);

private:
    sf::Font font;
    sf::Color fontColor, backColor;
    Board *board;
    int bombs, level;
    enum State
    {
        PLAYING,
        WON,
        LOST,
        MENU,
        REPLAY,
        EXIT
    } state;
};

#endif