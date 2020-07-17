Knight::Knight(FigureColor figureColor) :
    Figure(figureColor)
{
    setType(KNIGHT);
}

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
    int rowShift = start.first - destination.first;
    int columnShift = start.second - destination.second;

    return (abs(rowShift) == 2 && abs(columnShift) == 1) ||
           (abs(rowShift) == 1 && abs(columnShift) == 2);
}