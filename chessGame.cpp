ChessGame::ChessGame()
{
    this->board = Board();
    this->turn = WHITE;
    this->lastTakenFigure = EMPTY;  
}

void ChessGame::play()
{
    string continuePlaying = "y";
    while(continuePlaying == "y")
    {
        cout << "   _____ _    _ ______  _____ _____ " << endl
             << "  / ____| |  | |  ____|/ ____/ ____|" << endl
             << " | |    | |__| | |__  | (___| (___  " << endl
             << " | |    |  __  |  __|  \\___  \\___ \\" << endl
             << " | |____| |  | | |____ ____) |___) |" << endl
             << "  \\_____|_|  |_|______|_____/_____/" << endl;
            
        cout << "Enter any key to continue" << endl;
        string s;
        cin >> s;

        playOneChessGame();

        cout << "Do you want to play again? (y for yes, anything else for no): ";
        cin >> continuePlaying;
    }
}

void ChessGame::playOneChessGame()
{
    setChessGame();
    while(!thereIsWinner())
    {
        board.printBoard();
        if(turn == WHITE)
        {
            cout << "White's turn" << endl;
        }
        else
        {
		    cout << "Black's turn" << endl;
        }
		cout << "Type in your move as a single four character string. Use column index followed by row index in each pair." << endl;
        
        performMove();
        switchTurn();
    }

    switchTurn(); // switching the turn again because last turn wasn't playable and so we need to determine the winner
    announceWinner();
}

void ChessGame::setChessGame()
{
    board.setBoard();
    turn = WHITE;
}

bool ChessGame::thereIsWinner() const
{
    return lastTakenFigure == KING;
}

void ChessGame::performMove()
{
    readMove();
	bool validMove = false;
	try
    {
		validMove = isValidMove();
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
		performMove();

		return;
    }
	
	if(validMove)
	{
		moveFigure();
	}
}

void ChessGame::readMove()
{
    string move;
    cin >> move;
    
    int startRow = '8' - move[1];
    int startColumn = move[0] - 'A';
    int destinationRow = '8' - move[3];
    int destinationColumn = move[2] - 'A';
    this->start = {startRow, startColumn};
    this->destination = {destinationRow, destinationColumn};
}

bool ChessGame::isValidMove() const
{
    if(!inputInBounds())
    {
        throw invalid_argument("Input is out of bounds");
    }

    if(!figureOnTurn())
    {
        throw invalid_argument("You can move only the figures in your possession");
    }

    if(!landEmptyOrEnemy())
    {
        throw invalid_argument("You cannot land on your own figure");
    }

    if(!isReachable())
    {
        throw invalid_argument("You cannot land there, something is blocking your path");
    }
    
    return true;
}

bool ChessGame::inputInBounds() const
{
    bool startIsValid = isSquareOnBoard(start.first, start.second);
    bool destIsValid = isSquareOnBoard(destination.first, destination.second);

    return startIsValid && destIsValid;
}

bool ChessGame::isSquareOnBoard(int x, int y) const
{
    return  x >= 0 && 
            x < BOARD_ROWS &&
            y >= 0 && 
            y < BOARD_COLUMNS;
}

bool ChessGame::figureOnTurn() const
{
    bool isCorrectFigure = (board.getColor(start) == turn);

    return isCorrectFigure;
}

bool ChessGame::landEmptyOrEnemy() const
{
    bool validLand = (turn != board.getColor(destination));

    return validLand;
}

bool ChessGame::isReachable() const
{
    if(board.getType(start) == PAWN && start.second - destination.second != 0)
    {
        return isValidPawnAttack();
    }

    vector<pair<int, int>> path = generateMovePath();
    if(path.empty())
    {
        return false;
    }
    path.pop_back();
    
    // checks if generated path doesn't go over actual figures before the final step
    for(pair<int, int>& position : path)
    {
        if(board.getType(position) != EMPTY)
        {
            return false;
        }
    }

    return true;
}

bool ChessGame::isValidPawnAttack() const
{
    bool movesOneHorizontally = abs(start.second - destination.second) == 1;
    if(!(movesOneHorizontally))
    {
        return false;
    }

    int verticalMovement = destination.first - start.first;
    if(board.getColor(start) == WHITE)
    {
        return board.getColor(destination) == BLACK && verticalMovement == -1;
    }
    else
    {
        return board.getColor(destination) == WHITE && verticalMovement == 1;
    }
}

vector<pair<int, int>> ChessGame::generateMovePath() const
{
    Figure *figure = board.getFigure(start);
    vector<pair<int, int>> movePath = figure->generatePath(start, destination);

    return movePath;
}

void ChessGame::moveFigure()
{
    if(board.getSquare(destination).getType() != EMPTY)
    {
        lastTakenFigure = board.getType(destination);
    }

    // friended ChessGame to Board in order to gain access to setFigureOn
    Figure *newFigure = board.getSquare(start).getFigure();
    board.setFigureOn(newFigure, destination);
    
    EmptyFigure *emptyFigure = new EmptyFigure(EMPTY, NONE);
    board.setFigureOn(emptyFigure, start);
}

void ChessGame::switchTurn()
{
    if(turn == BLACK)
    {
        this->turn = WHITE;
    }
    else
    {
        this->turn = BLACK;
    }
}

void ChessGame::announceWinner() const
{
    if(turn == WHITE)
    {
        cout << "WHITE WINS" << endl;
    }  
    else
    {
        cout << "BLACK WINS" << endl;
    }
}