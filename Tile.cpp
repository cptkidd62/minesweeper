#include "Tile.hpp"

Tile::Tile() {}

Tile::Tile(int x, int y) {}

bool Tile::revert()
{
    if (!front)
    {
        front = true;
        sprite.setTexture(frontside);
        return true;
    }
    return false;
}

bool Tile::changeMark()
{
    if (!front)
    {
        if (!marked)
        {
            marked = true;
            sprite.setTexture(flag);
        }
        else
        {
            marked = false;
            sprite.setTexture(backside);
        }
        return true;
    }
    return false;
}

bool Tile::contains(sf::Vector2f mPos)
{
    return sprite.getGlobalBounds().contains(mPos);
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}