class EmptyFigure : public Figure
{
public:
    EmptyFigure(FigureType figureType, FigureColor figureColor, int figureX, int figureY) : 
        Figure(figureType, figureColor, figureX, figureY){}

    char printFigureOnBoard()
    {
        char emptySymbol = '_';

        return emptySymbol;
    }

    vector<pair<int, int>> generatePathOfPairs(int destinationX, int destinationY)
    {
        vector<pair<int, int>> pathOfPairs;
        
        return pathOfPairs;
    }
};