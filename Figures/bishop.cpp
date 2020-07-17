Bishop::Bishop(FigureColor figureColor) :
    Figure(figureColor)
{
    setType(BISHOP);
}

char Bishop::print()
{
    char bishopSymbol = (isWhite()) ? 'B' : 'b';

    return bishopSymbol;
}

vector<pair<int, int>> Bishop::generatePath(pair<int, int> start, pair<int, int> destination)
{
    vector<pair<int, int>> path;
    if(isAccessible(start, destination))
    {
        path = generatePathHelper(start, destination);
    }
    
    return path;
}

bool Bishop::isAccessible(pair<int, int> start, pair<int, int> destination) const
{
    return abs(start.first - destination.first) == abs(start.second - destination.second);
}

vector<pair<int, int>> Bishop::generatePathHelper(pair<int, int> start, pair<int, int> destination) const
{
    vector<pair<int, int>> path;

    int rowShift = destination.first - start.first;
    int columnShift = destination.second - start.second;

    int rowDirection = rowShift / (abs(rowShift));
    int columnDirection = columnShift / (abs(columnShift));

    int currentShift = 1;
    while(currentShift <= abs(rowShift))
    {
        path.push_back({start.first + rowDirection * currentShift, start.second + columnDirection * currentShift});
        currentShift++;
    }

    return path;
}