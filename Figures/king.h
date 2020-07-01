class King : public Figure
{
public:
    King(FigureType figureType, FigureColor figureColor);

    char print();
    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination);
    bool isAccessible(pair<int, int> start, pair<int, int> destination);
    bool isStraightMove(pair<int, int> start, pair<int, int> destination);
    bool isHorizontalMove(pair<int, int> start, pair<int, int> destination);
    bool isVerticalMove(pair<int, int> start, pair<int, int> destination);
    bool isDiagonalMove(pair<int, int> start, pair<int, int> destination);
};

#include "king.cpp"