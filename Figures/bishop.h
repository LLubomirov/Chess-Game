#ifndef __BISHOP_H
#define __BISHOP_H

class Bishop : public Figure
{
public:
    Bishop(FigureColor figureColor);

    char print();
    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination);
    bool isAccessible(pair<int, int> start, pair<int, int> destination) const;
    vector<pair<int, int>> generatePathHelper(pair<int, int> start, pair<int, int> destination) const;
};

#include "bishop.cpp"

#endif