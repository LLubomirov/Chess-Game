#ifndef __QUEEN_H
#define __QUEEN_H

class Queen : public Figure
{
public:
    Queen(FigureColor figureColor);

    char print();
    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination);
    bool isAccessible(pair<int, int> start, pair<int, int> destination) const;
    bool isStraightMove(pair<int, int> start, pair<int, int> destination) const;
    bool isHorizontalMove(pair<int, int> start, pair<int, int> destination) const;
    bool isVerticalMove(pair<int, int> start, pair<int, int> destination) const;
    bool isDiagonalMove(pair<int, int> start, pair<int, int> destination) const;
    vector<pair<int, int>> generatePathHelper(pair<int, int> start, pair<int, int> destination) const;
    vector<pair<int, int>> generateStraightPath(pair<int, int> start, pair<int, int> destination) const;
    vector<pair<int, int>> generateHorizontalPath(pair<int, int> start, pair<int, int> destination) const;
    vector<pair<int, int>> generateVerticalPath(pair<int, int> start, pair<int, int> destination) const;
    vector<pair<int, int>> generateDiagonalPath(pair<int, int> start, pair<int, int> destination) const;
};

#include "queen.cpp"

#endif