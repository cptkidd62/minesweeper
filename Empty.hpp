#ifndef EMPTY_HPP
#define EMPTY_HPP

#include "Tile.hpp"

class Empty : public Tile
{
public:
    Empty(int x, int y);

    int revert();

private:
};

#endif