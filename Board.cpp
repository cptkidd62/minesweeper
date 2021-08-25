#include "Board.hpp"

Board::Board(int x, int y, int size, int level)
{
    xpos = x;
    ypos = y;
    std::vector<int> src = generate(size, level * 3);
    int k = 0;
    for (int i : src)
    {
        Tile *ptr;
        if (i == -1)
        {
            ptr = new Bomb(x + k / size * 50, y + k % size * 50);
        }
        if (i == 0)
        {
            ptr = new Empty(x + k / size * 50, y + k % size * 50);
        }
        if (i > 0)
        {
            ptr = new Number(x + k / size * 50, y + k % size * 50, i);
        }
        tiles.push_back(ptr);
        k++;
    }
}

Board::~Board()
{
    for (Tile *t : tiles)
    {
        delete t;
    }
}

int Board::click(sf::Vector2f mPos, bool left)
{
    for (auto t : tiles)
    {
        if (t->contains(mPos))
        {
            if (left)
            {
                t->revert();
            }
            else
            {
                t->changeMark();
            }
            return 1;
        }
    }
    return 0;
}

std::vector<int> Board::generate(int size, int bombs)
{
    std::srand(time(NULL));
    std::vector<int> board;
    board.resize(size * size);
    for (int i = 0; i < bombs; i++)
    {
        int n;
        do
        {
            n = std::rand() % (size * size);
        } while (board[n] == -1);
        board[n] = -1;
    }
    for (int i = 0; i < size * size; i++)
    {
        if (board[i] == 0)
        {
            if (i - size - 1 >= 0 && (i - size - 1) / size == i / size - 1 && board[i - size - 1] == -1)
                board[i]++;
            if (i - size >= 0 && (i - size) / size == i / size - 1 && board[i - size] == -1)
                board[i]++;
            if (i - size + 1 >= 0 && (i - size + 1) / size == i / size - 1 && board[i - size + 1] == -1)
                board[i]++;
            if (i - 1 >= 0 && (i - 1) / size == i / size && board[i - 1] == -1)
                board[i]++;
            if (i + 1 < size * size && (i + 1) / size == i / size && board[i + 1] == -1)
                board[i]++;
            if (i + size - 1 < size * size && (i + size - 1) / size == i / size + 1 && board[i + size - 1] == -1)
                board[i]++;
            if (i + size < size * size && (i + size) / size == i / size + 1 && board[i + size] == -1)
                board[i]++;
            if (i + size + 1 < size * size && (i + size + 1) / size == i / size + 1 && board[i + size + 1] == -1)
                board[i]++;
        }
    }
    return board;
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (Tile *t : tiles)
    {
        target.draw(*t, states);
    }
}