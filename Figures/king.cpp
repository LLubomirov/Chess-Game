King::King(FigureColor figureColor) :
    Figure(figureColor)
{
    setType(KING);
}

char King::print()
{
    char kingSymbol = (isWhite()) ? 'K' : 'k';

    return kingSymbol;
}

vector<pair<int, int>> King::generatePath(pair<int, int> start, pair<int, int> destination)
{
    vector<pair<int, int>> path;
    if(isAccessible(start, destination))
    {
        path.push_back(destination);
    }
    
    return path;
}

bool King::isAccessible(pair<int, int> start, pair<int, int> destination) const
{
    return isStraightMove(start, destination) || 
           isDiagonalMove(start, destination);
}

bool King::isStraightMove(pair<int, int> start, pair<int, int> destination) const
{
    return isHorizontalMove(start, destination) || 
           isVerticalMove(start, destination);
}

bool King::isHorizontalMove(pair<int, int> start, pair<int, int> destination) const
{
    return start.first == destination.first && 
           abs(start.second - destination.second) == 1;
}

bool King::isVerticalMove(pair<int, int> start, pair<int, int> destination) const
{
    return abs(start.first - destination.first) == 1 && 
           start.second == destination.second;
}

bool King::isDiagonalMove(pair<int, int> start, pair<int, int> destination) const
{
    int rowShift = destination.first - start.first;
    int columnShift = destination.second - start.second;

    return abs(rowShift) == 1 && 
           abs(columnShift) == 1;
}