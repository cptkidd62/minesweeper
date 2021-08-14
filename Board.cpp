#include "Board.hpp"

Board::Board(int x, int y, int size)
{
    xpos = x;
    ypos = y;
    std::vector<int> src = {-1, 0, 1};
    int k = 0;
    for (int i : src)
    {
        Tile *ptr;
        if (i == -1)
        {
            ptr = new Bomb(x + k * 50, y);
        }
        if (i == 0)
        {
            ptr = new Empty(x + k * 50, y);
        }
        if (i == 1)
        {
            ptr = new Number(x + k * 50, y);
        }
        tiles.push_back(ptr);
        k++;
    }
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