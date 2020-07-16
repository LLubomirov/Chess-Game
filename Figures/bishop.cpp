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
    int startX = start.first;
    int startY = start.second;
    int xIncrement = (destination.first - startX) / (abs(destination.first - startX));
    int yIncrement = (destination.second - startY) / (abs(destination.second - startY));
    int i = 0;
    do
    {
        i++;
        path.push_back({startX + xIncrement*i, startY + yIncrement*i});
    }
    while(i < abs(startX - destination.first));

    return path;
}