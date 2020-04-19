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
    FigureType figureType;
    FigureColor figureColor;
    int figureX;
    int figureY;

public:
    virtual vector<pair<int, int>> generatePathOfPairs(int destinationX, int destinationY) = 0;
    virtual char printFigureOnBoard() = 0;

    Figure(FigureType figureType, FigureColor figureColor, int figureX, int figureY)
    {
        this->figureType = figureType;
        this->figureColor = figureColor;
        this->figureX = figureX;
        this->figureY = figureY;
    }

    bool isWhite() const
    {
        return this->figureColor == WHITE;
    }

    bool isBlack() const
    {
        return this->figureColor == BLACK;
    }
    
    bool isEmpty() const
    {
        return this->figureColor == NONE;
    }

    FigureColor getColor() const
    {
        return this->figureColor;
    }

    FigureType getType() const
    {
        return this->figureType;
    }

    int getFigureX() const
    {
        return this->figureX;
    }

    int getFigureY() const
    {
        return this->figureY;
    }

    void setFigureAndColor(FigureType newFigureType, FigureColor newFigureColor)
    {
        this->figureType = newFigureType;
        this->figureColor = newFigureColor;
    }

    void setPosition(int newFigureX, int newFigureY)
    {
        this->figureX = newFigureX;
        this->figureY = newFigureY;
    }
};