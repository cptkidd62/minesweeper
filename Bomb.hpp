#ifndef BOMB_HPP
#define BOMB_HPP

#include "Tile.hpp"

class Bomb : public Tile
{
public:
    Bomb(int x, int y);

    int revert();
    
private:
};

#endif