class King : public Figure
{
public:
    King(FigureType figureType, FigureColor figureColor) :
        Figure(figureType, figureColor){}

    char print()
    {
        char kingSymbol = (isWhite()) ? 'K' : 'k';

        return kingSymbol;
    }

    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination)
    {
        vector<pair<int, int>> path;
        if(isAccessible(start, destination))
        {
            path.push_back(destination);
        }
        
        return path;
    }

    bool isAccessible(pair<int, int> start, pair<int, int> destination)
    {
        return(isStraightMove(start, destination) || isDiagonalMove(start, destination));
    }

    bool isStraightMove(pair<int, int> start, pair<int, int> destination)
    {
        return isHorizontalMove(start, destination) || isVerticalMove(start, destination);
    }

    bool isHorizontalMove(pair<int, int> start, pair<int, int> destination)
    {
        return start.first == destination.first && abs(start.second - destination.second) == 1;
    }

    bool isVerticalMove(pair<int, int> start, pair<int, int> destination)
    {
        return abs(start.first - destination.first) == 1 && start.second == destination.second;
    }

    bool isDiagonalMove(pair<int, int> start, pair<int, int> destination)
    {
        return abs(start.first - destination.first) == abs(start.second - destination.second) && abs(start.first - destination.first) == 1;
    }
};
