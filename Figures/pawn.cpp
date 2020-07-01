class Pawn : public Figure
{
public:
    Pawn(FigureType figureType, FigureColor figureColor) :
        Figure(figureType, figureColor){}

    char print()
    {
        char pawnSymbol = (isWhite()) ? 'P' : 'p';

        return pawnSymbol;
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

    /// Handling diagonal attack move when validating input
    bool isAccessible(pair<int, int> start, pair<int, int> destination) 
    {
        int verticalIncrement = destination.first - start.first;
        int horizontalIncrement = destination.second - start.second;
        
        bool isValidVerticalMove = (abs(verticalIncrement) == 1 && horizontalIncrement == 0);
        bool isValidDiagonalMove = (abs(verticalIncrement) == 1 && abs(horizontalIncrement) == 1);

        return isValidVerticalMove || isValidDiagonalMove;
    }
};
