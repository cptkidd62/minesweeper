#include "Number.hpp"

Number::Number(int x, int y)
{
    backside.loadFromFile("img/tile.png");
    frontside.loadFromFile("img/1.png");
    flag.loadFromFile("img/flag.png");
    front = false;
    marked = false;
    sprite.setPosition(100 + x, 100 + y);
    sprite.setTexture(frontside);
    sprite.setScale(0.1, 0.1);
}