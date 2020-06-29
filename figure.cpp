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

public:
    virtual vector<pair<int, int>> generatePath(pair<int, int>, pair<int, int>) = 0;
    virtual char print() = 0;

    Figure(FigureType type, FigureColor color)
    {
        this->type = type;
        this->color = color;
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
};