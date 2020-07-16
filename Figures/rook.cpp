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
    return(isHorizontalMove(start, destination) || isVerticalMove(start, destination));
}

bool Rook::isHorizontalMove(pair<int, int> start, pair<int, int> destination) const
{
    return start.first == destination.first && start.second != destination.second;
}

bool Rook::isVerticalMove(pair<int, int> start, pair<int, int> destination) const
{
    return start.first != destination.first && start.second == destination.second;
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
    int startY = start.second;
    vector<pair<int, int>> path;
    int yIncrement = (destination.second - startY) / (abs(destination.second - startY));
    int currentY = startY;
    do
    {
        currentY += yIncrement;
        path.push_back({destination.first, currentY});    
    }
    while (currentY != destination.second);

    return path;
}

vector<pair<int, int>> Rook::generateVerticalPath(pair<int, int> start, pair<int, int> destination) const
{
    int startX = start.first;
    vector<pair<int, int>> path;
    int xIncrement = (destination.first - startX) / (abs(destination.first - startX));
    int currentX = startX;
    do
    {
        currentX += xIncrement;
        path.push_back({currentX, destination.second});  
    }
    while(currentX != destination.first);

    return path;
}