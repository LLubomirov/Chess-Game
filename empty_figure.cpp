class EmptyFigure : public Figure
{
public:
    EmptyFigure(FigureType figureType, FigureColor figureColor, int figureX, int figureY) : 
        Figure(figureType, figureColor, figureX, figureY){}

    char print()
    {
        char emptySymbol = '_';

        return emptySymbol;
    }

    vector<pair<int, int>> generatePath(int destinationX, int destinationY)
    {
        vector<pair<int, int>> path;
        
        return path;
    }
};