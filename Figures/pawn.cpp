Pawn::Pawn(FigureType figureType, FigureColor figureColor) :
    Figure(figureType, figureColor){}

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
    int verticalIncrement = destination.first - start.first;
    int horizontalIncrement = destination.second - start.second;
    
    bool isValidVerticalMove = (abs(verticalIncrement) == 1 && horizontalIncrement == 0);
    bool isValidDiagonalMove = (abs(verticalIncrement) == 1 && abs(horizontalIncrement) == 1);

    return isValidVerticalMove || isValidDiagonalMove;
}