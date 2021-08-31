#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Tile : public sf::Drawable
{
public:
    Tile();
    Tile(int x, int y);

    virtual int revert();
    int changeMark();
    bool contains(sf::Vector2f mPos);
    void setNeighbors(std::vector<Tile *> neigh);

protected:
    sf::Texture backside;
    sf::Texture frontside;
    sf::Texture flag;
    sf::Sprite sprite;
    bool front;
    bool marked;
    std::vector<Tile *> neighbors;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif