#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Board.hpp"

class Game
{
public:
    Game();
    ~Game();

    void runGame(sf::RenderWindow &window);

private:
    sf::Font font;
    sf::Color fontColor, backColor;
    Board *board;
    int bombs;
    enum State
    {
        PLAYING,
        WON,
        LOST,
        EXIT
    } state;
};

#endif