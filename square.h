#ifndef __SQUARE_H
#define __SQUARE_H

#include "./Figures/figure.h"
#include "./Figures/empty_figure.h"

class Square
{
public:
    Square();
    Square(Figure *figure);
    
    Figure *getFigure() const;
    FigureColor getColor() const;
    FigureType getType() const;

private:
    friend class Board;
    friend class ExtendedSquare;

    void setFigure(Figure*);

    Figure* figure;
};

#include "square.cpp"

#endif