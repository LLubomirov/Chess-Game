class King : public Figure
{
public:
    King(FigureType figureType, FigureColor figureColor, int figureX, int figureY) :
        Figure(figureType, figureColor, figureX, figureY){}

    char print()
    {
        char kingSymbol = (isWhite()) ? 'K' : 'k';

        return kingSymbol;
    }

    vector<pair<int, int>> generatePath(int destinationX, int destinationY)
    {
        vector<pair<int, int>> path;
        if(isAccessible(destinationX, destinationY))
        {
            path.push_back({destinationX, destinationY});
        }
        
        return path;
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
        return getX() == destinationX && abs(getY() - destinationY) == 1;
    }

    bool isVerticalMove(int destinationX, int destinationY)
    {
        return abs(getX() - destinationX) == 1 && getY() == destinationY;
    }

    bool isDiagonalMove(int destinationX, int destinationY)
    {
        return abs(getX() - destinationX) == abs(getY() - destinationY) && abs(getX() - destinationX) == 1;
    }
};