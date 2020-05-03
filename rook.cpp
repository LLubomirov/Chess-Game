class Rook : public Figure
{
public:
    Rook(FigureType figureType, FigureColor figureColor, int figureX, int figureY) :
        Figure(figureType, figureColor, figureX, figureY){}
        
    char print()
    {
        char rookSymbol = (isWhite()) ? 'R' : 'r';

        return rookSymbol;
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
        return(isHorizontalMove(destinationX, destinationY) || isVerticalMove(destinationX, destinationY));
    }

    bool isHorizontalMove(int destinationX, int destinationY)
    {
        return getX() == destinationX && getY() != destinationY;
    }

    bool isVerticalMove(int destinationX, int destinationY)
    {
        return getX() != destinationX && getY() == destinationY;
    }

    vector<pair<int, int>> generatePathHelper(int destinationX, int destinationY)
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
};