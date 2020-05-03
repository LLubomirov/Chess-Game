class Knight : public Figure
{
public:
    Knight(FigureType figureType, FigureColor figureColor, int figureX, int figureY) :
        Figure(figureType, figureColor, figureX, figureY){}

    char print()
    {
        char knightSymbol = (isWhite()) ? 'H' : 'h';

        return knightSymbol;
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
        return (abs(getX() - destinationX) == 2 && abs(getY() - destinationY) == 1) ||
               (abs(getX() - destinationX) == 1 && abs(getY() - destinationY) == 2);
    }
};