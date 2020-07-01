#ifndef __SQUARE_H
#define __SQUARE_H

#include "./Figures/figure.h"

class Square
{
public:

    Square();
    Square(Figure *figure);
    Figure *getFigure() const;
    FigureColor getColor() const;
    FigureType getType() const;
    void setFigure(Figure *newFigure);

private:
    Figure* figure;
};

#include "square.cpp"

#endif