#include "Number.hpp"

Number::Number(int x, int y, int n)
{
    backside.loadFromFile("img/tile.png");
    frontside.loadFromFile("img/" + std::to_string(n) + ".png");
    flag.loadFromFile("img/flag.png");
    front = false;
    marked = false;
    sprite.setPosition(100 + x, 100 + y);
    sprite.setTexture(backside);
    sprite.setScale(0.1, 0.1);
}