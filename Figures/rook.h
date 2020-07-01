class Rook : public Figure
{
public:
    Rook(FigureType figureType, FigureColor figureColor);
    char print();
    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination);
    bool isAccessible(pair<int, int> start, pair<int, int> destination);
    bool isHorizontalMove(pair<int, int> start, pair<int, int> destination);
    bool isVerticalMove(pair<int, int> start, pair<int, int> destination);
    vector<pair<int, int>> generatePathHelper(pair<int, int> start, pair<int, int> destination);
    vector<pair<int, int>> generateHorizontalPath(pair<int, int> start, pair<int, int> destination);
    vector<pair<int, int>> generateVerticalPath(pair<int, int> start, pair<int, int> destination);
};

#include "rook.cpp"