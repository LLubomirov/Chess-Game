Queen::Queen(FigureColor figureColor) : 
    Figure(figureColor)
{
    setType(QUEEN);
}

char Queen::print()
{
    char queenSymbol = (isWhite()) ? 'Q' : 'q';
    
    return queenSymbol;
}

vector<pair<int, int>> Queen::generatePath(pair<int, int> start, pair<int, int> destination)
{
    vector<pair<int, int>> path;
    if(isAccessible(start, destination))
    {
        path = generatePathHelper(start, destination);
    }

    return path;
}

bool Queen::isAccessible(pair<int, int> start, pair<int, int> destination) const
{
    return isStraightMove(start, destination) || 
           isDiagonalMove(start, destination);
}

bool Queen::isStraightMove(pair<int, int> start, pair<int, int> destination) const
{
    return isHorizontalMove(start, destination) || 
           isVerticalMove(start, destination);
}

bool Queen::isHorizontalMove(pair<int, int> start, pair<int, int> destination) const
{
    return start.first == destination.first && 
           start.second != destination.second;
}

bool Queen::isVerticalMove(pair<int, int> start, pair<int, int> destination) const
{
    return start.first != destination.first && start.second == destination.second;
}

bool Queen::isDiagonalMove(pair<int, int> start, pair<int, int> destination) const
{
    return abs(start.first - destination.first) == abs(start.second - destination.second);
}

vector<pair<int, int>> Queen::generatePathHelper(pair<int, int> start, pair<int, int> destination) const
{
    vector<pair<int, int>> path;
    if(isStraightMove(start, destination)) 
    {
        path = generateStraightPath(start, destination);
    } 
    else
    {
        path = generateDiagonalPath(start, destination);
    }

    return path;
}

vector<pair<int, int>> Queen::generateStraightPath(pair<int, int> start, pair<int, int> destination) const
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

vector<pair<int, int>> Queen::generateHorizontalPath(pair<int, int> start, pair<int, int> destination) const
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

vector<pair<int, int>> Queen::generateVerticalPath(pair<int, int> start, pair<int, int> destination) const
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

vector<pair<int, int>> Queen::generateDiagonalPath(pair<int, int> start, pair<int, int> destination) const
{
    int rowShift = destination.first - start.first;
    int columnShift = destination.second - start.second;

    int rowDirection = rowShift / (abs(rowShift));
    int columnDirection = columnShift / (abs(columnShift));

    vector<pair<int, int>> path;
    int currentShift = 1;
    while(currentShift <= abs(rowShift))
    {
        pair<int, int> newStep = {start.first + rowDirection * currentShift, start.second + columnDirection * currentShift};
        path.push_back(newStep);

        currentShift++;
    }

    return path;
}