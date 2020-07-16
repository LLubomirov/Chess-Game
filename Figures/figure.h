#ifndef __FIGURE_H
#define __FIGURE_H

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

enum FigureColor { NONE, WHITE, BLACK };
enum FigureType { EMPTY, KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN };

class Figure 
{
public:
    Figure(FigureColor color);
    virtual vector<pair<int, int>> generatePath(pair<int, int>, pair<int, int>) = 0;
    virtual char print() = 0;

    bool isWhite() const;
    bool isBlack() const;
    bool isEmpty() const;
    FigureColor getColor() const;
    FigureType getType() const;

protected:
    void setType(const FigureType type)
    {
        this->type = type;
    }
    
private:
    FigureType type;
    FigureColor color;
};

#include "figure.cpp"

#endif