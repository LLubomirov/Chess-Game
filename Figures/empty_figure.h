#ifndef __EMPTY_FIGURE_H
#define __EMPTY_FIGURE_H

class EmptyFigure : public Figure
{
public:
    EmptyFigure(FigureColor figureColor);

    char print() ;
    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination);
};

#include "empty_figure.cpp"

#endif