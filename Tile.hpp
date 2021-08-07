#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>

class Tile : public sf::Drawable
{
public:
    Tile();
    Tile(int x, int y);

    bool revert();
    bool changeMark();

protected:
    sf::Texture backside;
    sf::Texture frontside;
    sf::Texture flag;
    sf::Sprite sprite;
    bool front;
    bool marked;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif