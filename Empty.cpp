#include "Empty.hpp"

Empty::Empty(int x, int y)
{
    backside.loadFromFile("img/tile.png");
    frontside.loadFromFile("img/0.png");
    flag.loadFromFile("img/flag.png");
    front = false;
    marked = false;
    sprite.setPosition(100 + x, 100 + y);
    sprite.setTexture(backside);
    sprite.setScale(0.1, 0.1);
}

int Empty::revert()
{
    if (!front && !marked)
    {
        front = true;
        sprite.setTexture(frontside);
        int r = 1;
        for (auto n : neighbors)
        {
            r += n->revert();
        }
        return r;
    }
    return 0;
}