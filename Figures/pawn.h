#ifndef __PAWN_H
#define __PAWN_H

class Pawn : public Figure
{
public:
    Pawn(FigureColor figureColor);

    char print();
    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination);
    bool isAccessible(pair<int, int> start, pair<int, int> destination) const;
};

#include "pawn.cpp"

#endif 