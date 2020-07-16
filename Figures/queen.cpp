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
    return(isStraightMove(start, destination) || isDiagonalMove(start, destination));
}

bool Queen::isStraightMove(pair<int, int> start, pair<int, int> destination) const
{
    return isHorizontalMove(start, destination) || isVerticalMove(start, destination);
}

bool Queen::isHorizontalMove(pair<int, int> start, pair<int, int> destination) const
{
    return start.first == destination.first && start.second != destination.second;
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
    vector<pair<int, int>> path;

    int columnIncrement = destination.second - start.second;
    int directionOnColumn = columnIncrement / (abs(columnIncrement));

    int currentColumn = start.second;
    do
    {
        currentColumn += directionOnColumn;
        path.push_back({destination.first, currentColumn});    
    }
    while (currentColumn != destination.second);

    return path;
}

vector<pair<int, int>> Queen::generateVerticalPath(pair<int, int> start, pair<int, int> destination) const
{
    vector<pair<int, int>> path;

    int rowIncrement = destination.first - start.first;
    int directionOnRow = rowIncrement / (abs(rowIncrement));

    int currentRow = start.first;
    do
    {
        currentRow += directionOnRow;
        path.push_back({currentRow, destination.second});  
    }
    while(currentRow != destination.first);

    return path;
}

vector<pair<int, int>> Queen::generateDiagonalPath(pair<int, int> start, pair<int, int> destination) const
{
    vector<pair<int, int>> path;

    int rowIncrement = destination.first - start.first;
    int columnIncrement = destination.second - start.second;

    int directionOnRow = rowIncrement / (abs(rowIncrement));
    int directionOnColumn = columnIncrement / (abs(columnIncrement));
    
    int i = 0;
    do
    {
        i++;
        path.push_back({start.first + directionOnRow * i, start.second + directionOnColumn * i});
    }
    while(i < abs(rowIncrement));

    return path;
}