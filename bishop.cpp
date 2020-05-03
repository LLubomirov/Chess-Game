class Bishop : public Figure
{
public:
    Bishop(FigureType figureType, FigureColor figureColor, int figureX, int figureY) :
        Figure(figureType, figureColor, figureX, figureY){}

    char printFigureOnBoard()
    {
        char bishopSymbol = (isWhite()) ? 'B' : 'b';

        return bishopSymbol;
    }

    vector<pair<int, int>> generatePathOfPairs(int destinationX, int destinationY)
    {
        vector<pair<int, int>> pathOfPairs;
        if(isAccessible(destinationX, destinationY))
        {
            pathOfPairs = generatePathHelper(destinationX, destinationY);
        }
        
        return pathOfPairs;
    }

    bool isAccessible(int destinationX, int destinationY)
    {
        return abs(getX() - destinationX) == abs(getY() - destinationY);
    }

    vector<pair<int, int>> generatePathHelper(int destinationX, int destinationY)
    {
        vector<pair<int, int>> pathOfPairs;
        int startX = getX();
        int startY = getY();
        int xIncrement = (destinationX - startX) / (abs(destinationX - startX));
        int yIncrement = (destinationY - startY) / (abs(destinationY - startY));
        int i = 0;
        do
        {
            i++;
            pathOfPairs.push_back({startX + xIncrement*i, startY + yIncrement*i});
        }
        while(i < abs(startX - destinationX));

        return pathOfPairs;
    }
};