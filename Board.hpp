#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include "Bomb.hpp"
#include "Number.hpp"
#include "Empty.hpp"
#include <vector>

class Board : public sf::Drawable
{
public:
    Board();
    ~Board();

private:
    std::vector<Tile *> tiles;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif