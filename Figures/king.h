#ifndef __KING_H
#define __KING_H

class King : public Figure
{
public:
    King(FigureType figureType, FigureColor figureColor);

    char print();
    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination);
    bool isAccessible(pair<int, int> start, pair<int, int> destination) const;
    bool isStraightMove(pair<int, int> start, pair<int, int> destination) const;
    bool isHorizontalMove(pair<int, int> start, pair<int, int> destination) const;
    bool isVerticalMove(pair<int, int> start, pair<int, int> destination) const;
    bool isDiagonalMove(pair<int, int> start, pair<int, int> destination) const;
};

#include "king.cpp"

#endif 