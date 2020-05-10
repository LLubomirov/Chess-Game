class Pawn : public Figure
{
public:
    Pawn(FigureType figureType, FigureColor figureColor, int figureX, int figureY) :
        Figure(figureType, figureColor, figureX, figureY){}

    char print()
    {
        char pawnSymbol = (isWhite()) ? 'P' : 'p';

        return pawnSymbol;
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

    /// Handling diagonal attack move when validating input
    bool isAccessible(int destinationX, int destinationY) 
    {
        bool isHorizontal = (getX() == destinationX);
        int newY = destinationY - getY();
        bool validHorizontal = ((isWhite()) ? (newY == 1) : (newY == -1));

        return isHorizontal && validHorizontal;
    }
};
