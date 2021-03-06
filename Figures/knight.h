#ifndef __KNIGHT_H
#define __KNIGHT_H

class Knight : public Figure
{
public:
    Knight(FigureColor figureColor);

    char print();
    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination);
    bool isAccessible(pair<int, int> start, pair<int, int> destination) const;
};

#include "knight.cpp"

#endif