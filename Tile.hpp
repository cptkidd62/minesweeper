#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>

class Tile : public sf::Drawable
{
public:
    Tile(int x, int y);

private:
    sf::Sprite backside;
    sf::Sprite frontside;
    sf::Sprite image;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif