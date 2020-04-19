class King : public Figure
{
public:
    King(FigureType figureType, FigureColor figureColor, int figureX, int figureY) :
        Figure(figureType, figureColor, figureX, figureY){}

    char printFigureOnBoard()
    {
        char kingSymbol = (isWhite()) ? 'K' : 'k';
        return kingSymbol;
    }

    vector<pair<int, int>> generatePathOfPairs(int destinationX, int destinationY)
    {
        vector<pair<int, int>> pathOfPairs;
        if(isAccessible(destinationX, destinationY))
        {
            pathOfPairs.push_back({destinationX, destinationY});
        }
        return pathOfPairs;
    }

    bool isAccessible(int destinationX, int destinationY)
    {
        return(isStraightMove(destinationX, destinationY) || isDiagonalMove(destinationX, destinationY));
    }

    bool isStraightMove(int destinationX, int destinationY)
    {
        return isHorizontalMove(destinationX, destinationY) || isVerticalMove(destinationX, destinationY);
    }

    bool isHorizontalMove(int destinationX, int destinationY)
    {
        return getFigureX() == destinationX && abs(getFigureY() - destinationY) == 1;
    }

    bool isVerticalMove(int destinationX, int destinationY)
    {
        return abs(getFigureX() - destinationX) == 1 && getFigureY() == destinationY;
    }

    bool isDiagonalMove(int destinationX, int destinationY)
    {
        return abs(getFigureX() - destinationX) == abs(getFigureY() - destinationY) && abs(getFigureX() - destinationX) == 1;
    }
};