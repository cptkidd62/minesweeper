#include "Tile.hpp"

Tile::Tile() {}

Tile::Tile(int x, int y)
{
    
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}