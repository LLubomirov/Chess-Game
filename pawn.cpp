class Pawn : public Figure
{
public:
    Pawn(FigureType figureType, FigureColor figureColor, int figureX, int figureY) :
        Figure(figureType, figureColor, figureX, figureY){}

    char printFigureOnBoard()
    {
        char pawnSymbol = (isWhite()) ? 'P' : 'p';

        return pawnSymbol;
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
        return (isWhite()) ? (getFigureY() == destinationY - 1) : (getFigureY() == destinationY + 1);
    }
};
