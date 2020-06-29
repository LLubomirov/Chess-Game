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
        bool isVertical = (start.second == destination.second);
        int newX = destination.first - start.first;
        bool validVertical = ((isWhite()) ? (newX == -1) : (newX == 1));

        return isVertical && validVertical;
    }
};
