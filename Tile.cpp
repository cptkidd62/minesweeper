#include "Tile.hpp"

Tile::Tile() {}

Tile::Tile(int x, int y) {}

int Tile::revert()
{
    if (!front && !marked)
    {
        front = true;
        sprite.setTexture(frontside);
        return 1;
    }
    return 0;
}

int Tile::changeMark()
{
    if (!front)
    {
        if (!marked)
        {
            marked = true;
            sprite.setTexture(flag);
            return 1;
        }
        else
        {
            marked = false;
            sprite.setTexture(backside);
            return -1;
        }
    }
    return 0;
}

bool Tile::contains(sf::Vector2f mPos)
{
    return sprite.getGlobalBounds().contains(mPos);
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}