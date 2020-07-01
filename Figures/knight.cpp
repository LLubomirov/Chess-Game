Knight::Knight(FigureType figureType, FigureColor figureColor) :
    Figure(figureType, figureColor){}

char Knight::print()
{
    char knightSymbol = (isWhite()) ? 'H' : 'h';

    return knightSymbol;
}

vector<pair<int, int>> Knight::generatePath(pair<int, int> start, pair<int, int> destination)
{
    vector<pair<int, int>> path;
    if(isAccessible(start, destination))
    {
        path.push_back(destination);
    }
    
    return path;
}

bool Knight::isAccessible(pair<int, int> start, pair<int, int> destination) const
{
    return (abs(start.first - destination.first) == 2 && abs(start.second - destination.second) == 1) ||
            (abs(start.first - destination.first) == 1 && abs(start.second - destination.second) == 2);
}