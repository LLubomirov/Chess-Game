class Queen : public Figure
{
public:
    Queen(FigureType figureType, FigureColor figureColor, int figureX, int figureY) :
        Figure(figureType, figureColor, figureX, figureY){}

    char print()
    {
        char queenSymbol = (isWhite()) ? 'Q' : 'q';
        
        return queenSymbol;
    }

    vector<pair<int, int>> generatePath(int destinationX, int destinationY)
    {
        vector<pair<int, int>> path;
        if(isAccessible(destinationX, destinationY))
        {
            path = generatePathHelper(destinationX, destinationY);
        }

        return path;
    }

    bool isAccessible(int destinationX, int destinationY)
    {
        return(isStraightMove(destinationX, destinationY) || isDiagonalMove(destinationX, destinationY));
    }

    bool isStraightMove(int destinationX, int destinationY)
    {
        return isHorizontalMove(destinationX, destinationY) || isVerticalMove(destinationX, destinationY);
    }

    bool isHorizontalMove(int destinationX, int destinationY)
    {
        return getX() == destinationX && getY() != destinationY;
    }

    bool isVerticalMove(int destinationX, int destinationY)
    {
        return getX() != destinationX && getY() == destinationY;
    }

    bool isDiagonalMove(int destinationX, int destinationY)
    {
        return abs(getX() - destinationX) == abs(getY() - destinationY);
    }

    vector<pair<int, int>> generatePathHelper(int destinationX, int destinationY)
    {
        int startX = this->getX();
        vector<pair<int, int>> path;
        if(isStraightMove(destinationX, destinationY)) 
        {
            path = generateStraightPath(destinationX, destinationY);
        } 
        else
        {
            path = generateDiagonalPath(destinationX, destinationY);
        }

        return path;
    }

    
    vector<pair<int, int>> generateStraightPath(int destinationX, int destinationY)
    {
        vector<pair<int, int>> path;
        if(isHorizontalMove(destinationX, destinationY)) 
        {
            path = generateHorizontalPath(destinationX, destinationY);
        } 
        else
        {
            path = generateVerticalPath(destinationX, destinationY);
        }
        return path;
    }

    vector<pair<int, int>> generateHorizontalPath(int destinationX, int destinationY)
    {
        int startY = this->getY();
        vector<pair<int, int>> path;
        int yIncrement = (destinationY - startY) / (abs(destinationY - startY));
        int currentY = startY;
        do
        {
            currentY += yIncrement;
            path.push_back({destinationX, currentY});    
		}
        while (currentY != destinationY);

        return path;
    }

    vector<pair<int, int>> generateVerticalPath(int destinationX, int destinationY)
    {
        int startX = this->getX();
        vector<pair<int, int>> path;
        int xIncrement = (destinationX - startX) / (abs(destinationX - startX));
        int currentX = startX;
        do
        {
            currentX += xIncrement;
            path.push_back({currentX, destinationY});  
        }
        while(currentX != destinationX);

        return path;
    }

    vector<pair<int, int>> generateDiagonalPath(int destinationX, int destinationY)
    {
        vector<pair<int, int>> path;
        int startX = getX();
        int startY = getY();
        int xIncrement = (destinationX - startX) / (abs(destinationX - startX));
        int yIncrement = (destinationY - startY) / (abs(destinationY - startY));
        int i = 0;
        do
        {
            i++;
            path.push_back({startX + xIncrement*i, startY + yIncrement*i});
        }
        while(i < abs(startX - destinationX));

        return path;
    }
};