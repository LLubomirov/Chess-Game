#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

enum FigureColor { NONE, WHITE, BLACK };
enum FigureType { EMPTY, KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN };

class Square;

class Figure 
{
private:
    FigureType type;
    FigureColor color;
    int x;
    int y;

public:
    virtual vector<pair<int, int>> generatePath(int destinationX, int destinationY) = 0;
    virtual char print() = 0;

    Figure(FigureType type, FigureColor color, int x, int y)
    {
        this->type = type;
        this->color = color;
        this->x = x;
        this->y = y;
    }

    bool isWhite() const
    {
        return this->color == WHITE;
    }

    bool isBlack() const
    {
        return this->color == BLACK;
    }
    
    bool isEmpty() const
    {
        return this->color == NONE;
    }

    FigureColor getColor() const
    {
        return this->color;
    }

    FigureType getType() const
    {
        return this->type;
    }

    int getX() const
    {
        return this->x;
    }

    int getY() const
    {
        return this->y;
    }

    void setPosition(int newX, int newY)
    {
        this->x = newX;
        this->y = newY;
    }
};