class Queen : public Figure
{
public:
    Queen(FigureType figureType, FigureColor figureColor) :
        Figure(figureType, figureColor){}

    char print()
    {
        char queenSymbol = (isWhite()) ? 'Q' : 'q';
        
        return queenSymbol;
    }

    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination)
    {
        vector<pair<int, int>> path;
        if(isAccessible(start, destination))
        {
            path = generatePathHelper(start, destination);
        }

        return path;
    }

    bool isAccessible(pair<int, int> start, pair<int, int> destination)
    {
        return(isStraightMove(start, destination) || isDiagonalMove(start, destination));
    }

    bool isStraightMove(pair<int, int> start, pair<int, int> destination)
    {
        return isHorizontalMove(start, destination) || isVerticalMove(start, destination);
    }

    bool isHorizontalMove(pair<int, int> start, pair<int, int> destination)
    {
        return start.first == destination.first && start.second != destination.second;
    }

    bool isVerticalMove(pair<int, int> start, pair<int, int> destination)
    {
        return start.first != destination.first && start.second == destination.second;
    }

    bool isDiagonalMove(pair<int, int> start, pair<int, int> destination)
    {
        return abs(start.first - destination.first) == abs(start.second - destination.second);
    }

    vector<pair<int, int>> generatePathHelper(pair<int, int> start, pair<int, int> destination)
    {
        int startX = start.first;
        vector<pair<int, int>> path;
        if(isStraightMove(start, destination)) 
        {
            path = generateStraightPath(start, destination);
        } 
        else
        {
            path = generateDiagonalPath(start, destination);
        }

        return path;
    }

    
    vector<pair<int, int>> generateStraightPath(pair<int, int> start, pair<int, int> destination)
    {
        vector<pair<int, int>> path;
        if(isHorizontalMove(start, destination)) 
        {
            path = generateHorizontalPath(start, destination);
        } 
        else
        {
            path = generateVerticalPath(start, destination);
        }
        return path;
    }

    vector<pair<int, int>> generateHorizontalPath(pair<int, int> start, pair<int, int> destination)
    {
        int startY = start.second;
        vector<pair<int, int>> path;
        int yIncrement = (destination.second - startY) / (abs(destination.second - startY));
        int currentY = startY;
        do
        {
            currentY += yIncrement;
            path.push_back({destination.first, currentY});    
		}
        while (currentY != destination.second);

        return path;
    }

    vector<pair<int, int>> generateVerticalPath(pair<int, int> start, pair<int, int> destination)
    {
        int startX = start.first;
        vector<pair<int, int>> path;
        int xIncrement = (destination.first - startX) / (abs(destination.first - startX));
        int currentX = startX;
        do
        {
            currentX += xIncrement;
            path.push_back({currentX, destination.second});  
        }
        while(currentX != destination.first);

        return path;
    }

    vector<pair<int, int>> generateDiagonalPath(pair<int, int> start, pair<int, int> destination)
    {
        vector<pair<int, int>> path;
        int startX = start.first;
        int startY = start.second;
        int xIncrement = (destination.first - startX) / (abs(destination.first - startX));
        int yIncrement = (destination.second - startY) / (abs(destination.second - startY));
        int i = 0;
        do
        {
            i++;
            path.push_back({startX + xIncrement*i, startY + yIncrement*i});
        }
        while(i < abs(startX - destination.first));

        return path;
    }
};
