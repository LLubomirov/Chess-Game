#ifndef __ROOK_H
#define __ROOK_H

class Rook : public Figure
{
public:
    Rook(FigureType figureType, FigureColor figureColor);
    
    char print();
    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination);
    bool isAccessible(pair<int, int> start, pair<int, int> destination) const;
    bool isHorizontalMove(pair<int, int> start, pair<int, int> destination) const;
    bool isVerticalMove(pair<int, int> start, pair<int, int> destination) const;
    vector<pair<int, int>> generatePathHelper(pair<int, int> start, pair<int, int> destination) const;
    vector<pair<int, int>> generateHorizontalPath(pair<int, int> start, pair<int, int> destination) const;
    vector<pair<int, int>> generateVerticalPath(pair<int, int> start, pair<int, int> destination) const;
};

#include "rook.cpp"

#endif