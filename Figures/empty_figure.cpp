class EmptyFigure : public Figure
{
public:
    EmptyFigure(FigureType figureType, FigureColor figureColor) : 
        Figure(figureType, figureColor){}

    char print()
    {
        char emptySymbol = '_';

        return emptySymbol;
    }

    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination)
    {
        vector<pair<int, int>> path;
        
        return path;
    }
};
