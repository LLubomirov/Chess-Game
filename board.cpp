#include "board.h"

Board::Board()
{
	this->turn = WHITE;
	this->lastTakenFigure = EMPTY;

	for(int i = 0; i < BOARD_ROWS; ++i)
	{
		for(int j = 0; j < BOARD_COLUMNS; ++j)
		{
			this->board[i][j].setFigure(new EmptyFigure (EMPTY, NONE));
		}
	}
	
	this->start = &board[0][0];
	this->destination = &board[0][0];
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

void Board::setBoard()
{
	board[7][7].setFigure(new Rook  (ROOK,   WHITE));
	board[7][6].setFigure(new Knight(KNIGHT, WHITE));
	board[7][5].setFigure(new Bishop(BISHOP, WHITE));
	board[7][4].setFigure(new Queen (QUEEN,  WHITE));
	board[7][3].setFigure(new King  (KING,   WHITE));
	board[7][2].setFigure(new Bishop(BISHOP, WHITE));
	board[7][1].setFigure(new Knight(KNIGHT, WHITE));
	board[7][0].setFigure(new Rook  (ROOK,   WHITE));

	board[0][7].setFigure(new Rook  (ROOK,   BLACK));
	board[0][6].setFigure(new Knight(KNIGHT, BLACK));
	board[0][5].setFigure(new Bishop(BISHOP, BLACK));
	board[0][4].setFigure(new Queen (QUEEN,  BLACK));
	board[0][3].setFigure(new King  (KING,   BLACK));
	board[0][2].setFigure(new Bishop(BISHOP, BLACK));
	board[0][1].setFigure(new Knight(KNIGHT, BLACK));
	board[0][0].setFigure(new Rook  (ROOK,   BLACK));

	for (int i = 0; i < BOARD_COLUMNS; i++)
	{
		board[1][i].setFigure(new Pawn(PAWN, BLACK));
		board[6][i].setFigure(new Pawn(PAWN, WHITE));
	}
}

void Board::setStart(Square *start)
{
	this->start = start;
}

void Board::setDestination(Square *destination)
{
	this->destination = destination;
}

bool Board::thereIsWinner()
{
	return lastTakenFigure == KING;
}

void Board::printBoard() 
{
	// system("cls");
	for (int i = 0; i < BOARD_ROWS; i++)
	{
		cout << i << "  ";
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
		cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
			
}

void Board::performMove()
{
	readMove();
	validateMove();
	moveFigure();
}

void Board::readMove()
{
	string move;
	cin >> move;
	
	int startX = move[1] - '0';
	int startY = move[0] - 'A';
	int destinationX = move[3] - '0';
	int destinationY = move[2] - 'A';

	
	if(isSquareOnBoard(startX, startY) &&
	   isSquareOnBoard(destinationX, destinationY))
	{
		setStart(&board[startX][startY]);
		setDestination(&board[destinationX][destinationY]);
		this->startCoords = {startX, startY};
		this->destCoords = {destinationX, destinationY};
	}
	else
	{	///fix this
		setStart(nullptr);
		setDestination(nullptr);
	}
}

void Board::validateMove() 
{
	while(!isValidMove())
	{
		cout << "Try again" << endl;
		readMove();
	}
}

void Board::moveFigure()
{
	if(destination->getType() != EMPTY)
	{
		lastTakenFigure = destination->getType();
	}

	destination->setFigure(start->getFigure());
	EmptyFigure *emptyFigure = new EmptyFigure(EMPTY, NONE);
	start->setFigure(emptyFigure);
}

int Board::charToInt(char input)
{
	int num = input - 48;
	return num;
}

bool Board::isValidMove()
{
	bool inBounds = inputInBounds();
	bool figureTurn = figureOnTurn();
	bool landable = canLand();
	bool reachable = isReachable(); 

	if(!inBounds)
	{
		cout << "Input is in bounds: " << boolalpha << inBounds << endl;
	}

	if(!figureTurn)
	{
		cout << "Figure is on turn :  " << boolalpha << figureTurn << endl;
	}

	if(!landable)
	{
		cout << "Square is landable:  " << boolalpha << landable   << endl;
	}

	if(!reachable)
	{
		cout << "Square is reachable: " << boolalpha << reachable  << endl;
	}
	
	return inBounds &&
			figureTurn &&
			landable &&
			reachable;

	/*
	return inputInBounds() &&
		   figureOnTurn() &&
		   canLand() &&
		   isReachable(); 
	*/
}

bool Board::inputInBounds()
{
	bool inBounds = (start != nullptr && destination != nullptr);

	if(!inBounds)
	{
		cout << "Your input is out of bounds!" << endl;
	}

	return inBounds;
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
	bool isCorrectFigure = (start->getColor() == turn);

	if(!isCorrectFigure) 
	{
		cout << "You don't have figure there!" << endl;
	}

	return isCorrectFigure;
}

bool Board::canLand()
{
	bool validLand = (start->getColor() != destination->getColor());

	if(!validLand)
	{
		cout << "You can't land on your own figure!" << endl;
	}

	return validLand;
}

bool Board::isReachable()
{
	return isRegularMove() || isPawnAttack();
}

bool Board::isPawnAttack()
{
	bool isPawnMove = start->getType() == PAWN;
	bool movesOneHorizontally = abs(startCoords.second - destCoords.second) == 1;

	if(!(isPawnMove && movesOneHorizontally))
	{
		return false;
	}

	int xMovement = destCoords.first - startCoords.first;

	if(start->getColor() == WHITE)
	{
		return destination->getColor() == BLACK && 
		       xMovement == -1;
	}

	else
	{
		return destination->getColor() == WHITE && 
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
	
	for(pair<int, int> &p : path) ///check if generated path doesn't go over actual figures
	{
		if(board[p.first][p.second].getType() != EMPTY)
		{
			return false;
		}
	}

	if(isPawnHorizontal())
	{
		bool stepOnEmpty = destination->getType() == EMPTY;

		return stepOnEmpty;
	}

	return true;
}

bool Board::isPawnHorizontal()
{	
	bool isPawn = start->getType() == PAWN;
	bool isHorizontal = (startCoords.first == destCoords.first);

	return isPawn && isHorizontal;
}

vector<pair<int, int>> Board::generatePath()
{
	Figure* startFigure = start->getFigure();

	vector<pair<int, int>> path = startFigure->generatePath(startCoords, destCoords);

	return path;
}

void Board::switchPlayerTurn()
{
	(turn == BLACK) ? turn = WHITE : turn = BLACK;
}