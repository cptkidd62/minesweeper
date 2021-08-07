#include "Board.hpp"

Board::Board()
{
    tiles.push_back(new Bomb(0, 0));
}

Board::~Board()
{
    for (Tile* t : tiles)
    {
        delete t;
    }
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (Tile* t : tiles)
    {
        target.draw(*t, states);
    }
}