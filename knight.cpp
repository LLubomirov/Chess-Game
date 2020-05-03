class Knight : public Figure
{
public:
    Knight(FigureType figureType, FigureColor figureColor, int figureX, int figureY) :
        Figure(figureType, figureColor, figureX, figureY){}

    char printFigureOnBoard()
    {
        char knightSymbol = (isWhite()) ? 'H' : 'h';

        return knightSymbol;
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
        return (abs(getX() - destinationX) == 2 && abs(getY() - destinationY) == 1) ||
               (abs(getX() - destinationX) == 1 && abs(getY() - destinationY) == 2);
    }
};