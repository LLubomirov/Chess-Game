EmptyFigure::EmptyFigure(FigureColor figureColor) : 
    Figure(figureColor)
{
    setType(EMPTY);
}

char EmptyFigure::print()
{
    char emptySymbol = '_';

    return emptySymbol;
}

vector<pair<int, int>> EmptyFigure::generatePath(pair<int, int> start, pair<int, int> destination)
{
    vector<pair<int, int>> path;
    
    return path;
}