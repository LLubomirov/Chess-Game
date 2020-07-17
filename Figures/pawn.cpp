Pawn::Pawn(FigureColor figureColor) :
    Figure(figureColor)
{
    setType(PAWN);
}

char Pawn::print()
{
    char pawnSymbol = (isWhite()) ? 'P' : 'p';

    return pawnSymbol;
}

vector<pair<int, int>> Pawn::generatePath(pair<int, int> start, pair<int, int> destination)
{
    vector<pair<int, int>> path;
    if(isAccessible(start, destination))
    {
        path.push_back(destination);
    }
    
    return path;
}

bool Pawn::isAccessible(pair<int, int> start, pair<int, int> destination) const
{
    int rowShift = destination.first - start.first;
    int columnShift = destination.second - start.second;
    
    bool isValidVerticalMove = (abs(rowShift) == 1 && columnShift == 0);
    bool isCorrectDirection = false;
    if(getColor() == WHITE)
    {
        isCorrectDirection = (rowShift == -1);
    }
    else
    {
        isCorrectDirection = (rowShift == 1);
    }

    return isValidVerticalMove && isCorrectDirection;
}