class Knight : public Figure
{
public:
    Knight(FigureType figureType, FigureColor figureColor) :
        Figure(figureType, figureColor){}

    char print()
    {
        char knightSymbol = (isWhite()) ? 'H' : 'h';

        return knightSymbol;
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
        return (abs(start.first - destination.first) == 2 && abs(start.second - destination.second) == 1) ||
               (abs(start.first - destination.first) == 1 && abs(start.second - destination.second) == 2);
    }
};
