class EmptyFigure : public Figure
{
public:
    EmptyFigure(FigureType figureType, FigureColor figureColor);

    char print() ;
    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination);
};

#include "empty_figure.cpp"