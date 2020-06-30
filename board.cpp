#include "board.h"

Board::Board()
{
	this->turn = WHITE;
	this->lastTakenFigure = EMPTY;

	for(int i = 0; i < BOARD_ROWS; ++i)
	{
		for(int j = 0; j < BOARD_COLUMNS; ++j)
		{
			setFigureOn(new EmptyFigure (EMPTY, NONE), {i, j});
		}
	}
}

void Board::playGame()
{
	setBoard();
	while(!thereIsWinner())
	{
		printBoard(); 
		performMove();
		switchPlayerTurn();
	}

	switchPlayerTurn();
	(turn == WHITE) ? cout << "WHITE WINS\n" : cout << "BLACK WINS\n";
}

Square Board::getSquare(pair<int, int> position)
{
	///throw exception if invalid position
	return this->board[position.first][position.second];
}

FigureColor Board::getColor(pair<int, int> position)
{
	return this->board[position.first][position.second].getColor();
}

FigureType Board::getType(pair<int, int> position)
{
	return this->board[position.first][position.second].getType();
}

void Board::setBoard()
{
	setFigureOn(new Rook  (ROOK,   WHITE), {7, 7});
	setFigureOn(new Knight(KNIGHT, WHITE), {7, 6});
	setFigureOn(new Bishop(BISHOP, WHITE), {7, 5});
	setFigureOn(new King  (KING,   WHITE), {7, 4});
	setFigureOn(new Queen (QUEEN,  WHITE), {7, 3});
	setFigureOn(new Bishop(BISHOP, WHITE), {7, 2});
	setFigureOn(new Knight(KNIGHT, WHITE), {7, 1});
	setFigureOn(new Rook  (ROOK,   WHITE), {7, 0});

	setFigureOn(new Rook  (ROOK,   BLACK), {0, 7});
	setFigureOn(new Knight(KNIGHT, BLACK), {0, 6});
	setFigureOn(new Bishop(BISHOP, BLACK), {0, 5});
	setFigureOn(new King  (KING,   BLACK), {0, 4});
	setFigureOn(new Queen (QUEEN,  BLACK), {0, 3});
	setFigureOn(new Bishop(BISHOP, BLACK), {0, 2});
	setFigureOn(new Knight(KNIGHT, BLACK), {0, 1});
	setFigureOn(new Rook  (ROOK,   BLACK), {0, 0});

	for (int i = 0; i < BOARD_COLUMNS; i++)
	{
		setFigureOn(new Pawn(PAWN, BLACK), {1, i});
		setFigureOn(new Pawn(PAWN, WHITE), {6, i});
	}
}

void Board::setFigureOn(Figure *figure, pair<int, int> position)
{
	this->board[position.first][position.second].setFigure(figure);
}


// void Board::setStart(Square *start)
// {
// 	this->start = start;
// }

// void Board::setDestination(Square *destination)
// {
// 	this->destination = destination;
// }

bool Board::thereIsWinner()
{
	return lastTakenFigure == KING;
}

void Board::printBoard() 
{
	// system("cls");
	for (int i = 0; i < BOARD_ROWS; i++)
	{
		cout << 8 - i << "  ";
		for (int j = 0; j < BOARD_COLUMNS; j++)
		{
			cout << " ";
			char figure = board[i][j].getFigure()->print();
			cout << figure;
			cout << " ";
		}
		cout << endl;
	}
	cout << endl << "    A  B  C  D  E  F  G  H " << endl;

	(turn == WHITE) ? cout << "White's turn" << endl : 
		cout << "Black's turn" << endl;
		cout << "Type in your move as a single four character string. Use column index followed by row index in each pair." << endl;
			
}

void Board::performMove()
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

void Board::readMove()
{
	string move;
	cin >> move;
	
	int startX = '8' - move[1];
	int startY = move[0] - 'A';
	int destinationX = '8' - move[3];
	int destinationY = move[2] - 'A';
	this->startCoords = {startX, startY};
	this->destCoords = {destinationX, destinationY};
}

void Board::moveFigure()
{
	if(getSquare(destCoords).getType() != EMPTY)
	{
		lastTakenFigure = getType(destCoords);
	}

	Figure *newFigure = getSquare(startCoords).getFigure();
	setFigureOn(newFigure, destCoords);
	
	EmptyFigure *emptyFigure = new EmptyFigure(EMPTY, NONE);
	setFigureOn(emptyFigure, startCoords);
}

int Board::charToInt(char input)
{
	int num = input - 48;
	return num;
}

bool Board::isValidMove()
{
	if(!inputInBounds())
	{
		throw invalid_argument("Input is out of bounds");
	}

	if(!figureOnTurn())
	{
		throw invalid_argument("You can move only the figures in your possession");
	}

	if(!canLandOn())
	{
		throw invalid_argument("You cannot land on your own figure");
	}

	if(!isReachable())
	{
		throw invalid_argument("You cannot land there, something is blocking your path");
	}
	
	return true;
}

bool Board::inputInBounds()
{
	bool startIsValid = startCoords.first >= 0 && startCoords.first <= 7 &&
						startCoords.second >= 0 && startCoords.second <= 7;

	bool destIsValid = destCoords.first >= 0 && destCoords.first <= 7 &&
						destCoords.second >= 0 && destCoords.second <= 7;
	// bool inBounds = (start != nullptr && destination != nullptr);

	// if(!inBounds)
	// {
	// 	cout << "Your input is out of bounds!" << endl;
	// }
	// cout << "Is in bound: " << boolalpha << (startIsValid && destIsValid) << endl;

	return startIsValid && destIsValid;
}

bool Board::isSquareOnBoard(int x, int y)
{
	return  x >= 0 && 
			x < BOARD_ROWS &&
			y >= 0 && 
			y < BOARD_COLUMNS;
}

bool Board::figureOnTurn()
{
	bool isCorrectFigure = (getColor(startCoords) == turn);

	// cout << getSquare(startCoords).getColor() << " == " << turn << endl;
	// if(!isCorrectFigure) 
	// {
	// 	cout << "You don't have figure there!" << endl;
	// }
	// cout << "figureOnTurn(): " << boolalpha << isCorrectFigure << endl;

	return isCorrectFigure;
}

bool Board::canLandOn()
{
	bool validLand = (turn != getColor(destCoords));

	// if(!validLand)
	// {
	// 	cout << "You can't land on your own figure!" << endl;
	// }

	return validLand;
}

bool Board::isReachable()
{
	return isRegularMove() || isPawnAttack();
}

bool Board::isPawnAttack()
{
	bool isPawnMove = getType(startCoords) == PAWN;
	bool movesOneHorizontally = abs(startCoords.second - destCoords.second) == 1;

	if(!(isPawnMove && movesOneHorizontally))
	{
		return false;
	}

	int xMovement = destCoords.first - startCoords.first;

	if(getColor(startCoords) == WHITE)
	{
		return getColor(destCoords) == BLACK && 
		       xMovement == -1;
	}

	else
	{
		return getColor(destCoords) == WHITE && 
		       xMovement == 1;
	}
}

bool Board::isRegularMove()
{
	vector<pair<int, int>> path = generatePath();

	if(path.empty())
	{
		return false;
	}

	path.pop_back();
	
	for(pair<int, int>& position : path) ///check if generated path doesn't go over actual figures
	{
		if(getType(position) != EMPTY)
		{
			return false;
		}
	}

	if(isPawnHorizontal())
	{
		bool stepOnEmpty = getType(destCoords) == EMPTY;

		return stepOnEmpty;
	}

	return true;
}

bool Board::isPawnHorizontal()
{	
	bool isPawn = getType(startCoords) == PAWN;
	bool isHorizontal = (startCoords.first == destCoords.first);

	return isPawn && isHorizontal;
}

vector<pair<int, int>> Board::generatePath()
{
	Figure* startFigure = getSquare(startCoords).getFigure();

	vector<pair<int, int>> path = startFigure->generatePath(startCoords, destCoords);

	return path;
}

void Board::switchPlayerTurn()
{
	(turn == BLACK) ? turn = WHITE : turn = BLACK;
}