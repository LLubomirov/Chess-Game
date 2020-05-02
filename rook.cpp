class Rook : public Figure
{
public:
    Rook(FigureType figureType, FigureColor figureColor, int figureX, int figureY) :
        Figure(figureType, figureColor, figureX, figureY){}
        
    char printFigureOnBoard()
    {
        char rookSymbol = (isWhite()) ? 'R' : 'r';

        return rookSymbol;
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
        return(isHorizontalMove(destinationX, destinationY) || isVerticalMove(destinationX, destinationY));
    }

    bool isHorizontalMove(int destinationX, int destinationY)
    {
        return getFigureX() == destinationX && getFigureY() != destinationY;
    }

    bool isVerticalMove(int destinationX, int destinationY)
    {
        return getFigureX() != destinationX && getFigureY() == destinationY;
    }

    vector<pair<int, int>> generatePathHelper(int destinationX, int destinationY)
    {
        vector<pair<int, int>> pathOfPairs;
        if(isHorizontalMove(destinationX, destinationY)) 
        {
            pathOfPairs = generateHorizontalPath(destinationX, destinationY);
        } 
        else
        {
            pathOfPairs = generateVerticalPath(destinationX, destinationY);
        }

        return pathOfPairs;
    }

    vector<pair<int, int>> generateHorizontalPath(int destinationX, int destinationY)
    {
        int startY = this->getFigureY();
        vector<pair<int, int>> pathOfPairs;
        int yIncrement = (destinationY - startY) / (abs(destinationY - startY));
        int currentY = startY;
        do
        {
            currentY += yIncrement;
            pathOfPairs.push_back({destinationX, currentY});    
		}
        while (currentY != destinationY);

        return pathOfPairs;
    }

    vector<pair<int, int>> generateVerticalPath(int destinationX, int destinationY)
    {
        int startX = this->getFigureX();
        vector<pair<int, int>> pathOfPairs;
        int xIncrement = (destinationX - startX) / (abs(destinationX - startX));
        int currentX = startX;
        do
        {
            currentX += xIncrement;
            pathOfPairs.push_back({currentX, destinationY});  
        }
        while(currentX != destinationX);

        return pathOfPairs;
    }
};