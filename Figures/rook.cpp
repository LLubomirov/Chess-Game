Rook::Rook(FigureColor figureColor) :
    Figure(figureColor)
{
    setType(ROOK);
}
    
char Rook::print()
{
    char rookSymbol = (isWhite()) ? 'R' : 'r';

    return rookSymbol;
}

vector<pair<int, int>> Rook::generatePath(pair<int, int> start, pair<int, int> destination)
{
    vector<pair<int, int>> path;
    if(isAccessible(start, destination))
    {
        path = generatePathHelper(start, destination);
    }
    
    return path;
}

bool Rook::isAccessible(pair<int, int> start, pair<int, int> destination) const
{
    return isHorizontalMove(start, destination) || 
           isVerticalMove(start, destination);
}

bool Rook::isHorizontalMove(pair<int, int> start, pair<int, int> destination) const
{
    return start.first == destination.first && 
           start.second != destination.second;
}

bool Rook::isVerticalMove(pair<int, int> start, pair<int, int> destination) const
{
    return start.first != destination.first && 
           start.second == destination.second;
}

vector<pair<int, int>> Rook::generatePathHelper(pair<int, int> start, pair<int, int> destination) const
{
    vector<pair<int, int>> path;
    if(isHorizontalMove(start, destination)) 
    {
        path = generateHorizontalPath(start, destination);
    } 
    else
    {
        path = generateVerticalPath(start, destination);
    }

    return path;
}

vector<pair<int, int>> Rook::generateHorizontalPath(pair<int, int> start, pair<int, int> destination) const
{
    int columnShift = destination.second - start.second;
    int columnDirection = columnShift / (abs(columnShift));

    vector<pair<int, int>> path;
    int currentShift = 1;
    while (currentShift <= abs(columnShift))
    {
        pair<int, int> newStep = {start.first, start.second + columnDirection * currentShift};
        path.push_back(newStep);

        currentShift++;
    }

    return path;
}

vector<pair<int, int>> Rook::generateVerticalPath(pair<int, int> start, pair<int, int> destination) const
{
    int rowShift = destination.first - start.first;
    int rowDirection = rowShift / (abs(rowShift));

    vector<pair<int, int>> path;
    int currentShift = 1;
    while(currentShift <= abs(rowShift))
    {
        pair<int, int> newStep = {start.first + rowDirection * currentShift, start.second};
        path.push_back(newStep);

        currentShift++;
    }

    return path;
}