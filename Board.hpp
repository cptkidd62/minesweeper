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
    Board(int x, int y, int size, int level);
    ~Board();

    // int returns move type
    std::pair<int, int> click(sf::Vector2f mPos, bool left);

private:
    int xpos, ypos;
    int bombsLeft;
    int toRevert;
    std::vector<Tile *> tiles;

    std::vector<int> generate(int size, int bombs);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif