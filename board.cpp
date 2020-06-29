#include "board.h"

Board::Board()
{
	this->turn = WHITE;
	this->lastTakenFigure = EMPTY;

	for(int i = 0; i < BOARD_ROWS; ++i)
	{
		for(int j = 0; j < BOARD_COLUMNS; ++j)
		{
			this->board[i][j].setFigure(new EmptyFigure (EMPTY, NONE, i, j));
		}
	}
	cout << "board[0][0]: [" << board[0][0].getX() << ", " << board[0][0].getY() << "]" << endl;
	this->start = &board[0][0];
	this->destination = &board[0][0];
}

void Board::playGame()
{
	setBoard();
	while(!thereIsWinner())
	{
		printBoard(); 
		readMove();

		// cout << "playGame()\n";
		// cout << "start=board[" << start->getX() << "][" << start->getY() << "]" << endl;
		// cout << "dest =board[" << destination->getX() << "][" << destination->getY() << "]" << endl;

		validateMove();
		moveFigure(); 
		switchPlayerTurn();
	}

	switchPlayerTurn();
	(turn == WHITE) ? cout << "WHITE WINS\n" : cout << "BLACK WINS\n";
}

void Board::setBoard()
{
	board[7][7].setFigure(new Rook  (ROOK,   WHITE, 7, 7));
	board[7][6].setFigure(new Knight(KNIGHT, WHITE, 7, 6));
	board[7][5].setFigure(new Bishop(BISHOP, WHITE, 7, 5));
	board[7][4].setFigure(new Queen (QUEEN,  WHITE, 7, 4));
	board[7][3].setFigure(new King  (KING,   WHITE, 7, 3));
	board[7][2].setFigure(new Bishop(BISHOP, WHITE, 7, 2));
	board[7][1].setFigure(new Knight(KNIGHT, WHITE, 7, 1));
	board[7][0].setFigure(new Rook  (ROOK,   WHITE, 7, 0));

	board[0][7].setFigure(new Rook  (ROOK,   BLACK, 0, 7));
	board[0][6].setFigure(new Knight(KNIGHT, BLACK, 0, 6));
	board[0][5].setFigure(new Bishop(BISHOP, BLACK, 0, 5));
	board[0][4].setFigure(new Queen (QUEEN,  BLACK, 0, 4));
	board[0][3].setFigure(new King  (KING,   BLACK, 0, 3));
	board[0][2].setFigure(new Bishop(BISHOP, BLACK, 0, 2));
	board[0][1].setFigure(new Knight(KNIGHT, BLACK, 0, 1));
	board[0][0].setFigure(new Rook  (ROOK,   BLACK, 0, 0));

	for (int i = 0; i < BOARD_COLUMNS; i++)
	{
		board[1][i].setFigure(new Pawn(PAWN, BLACK, 1, i));
		board[6][i].setFigure(new Pawn(PAWN, WHITE, 6, i));
	}
}

void Board::setStart(Square *start)
{
	// cout << "setStart()" << endl;
	// cout << "start[" << _start->getX() << ", " << _start->getY() << "]" << endl;
	this->start = start;
	// cout << "start=board[" << start->getX() << ", " << start->getY() << "]" << endl;
}

void Board::setDestination(Square *destination)
{
	// cout << "setDestination()" << endl;
	// cout << "dest[" << _destination->getX() << ", " << _destination->getY() << "]" << endl;
	this->destination = destination;
	// cout << "dest=board[" << destination->getX() << ", " << destination->getY() << "]" << endl;
}

bool Board::thereIsWinner()
{
	return lastTakenFigure == KING;
}

void Board::printBoard() 
{
	// system("cls");
	cout << "   y: 0  1  2  3  4  5  6  7 " << endl << "x:" << endl;
	for (int i = 0; i < BOARD_ROWS; i++)
	{
		cout << " " << i << "   ";
		for (int j = 0; j < BOARD_COLUMNS; j++)
		{
			cout << " ";
			char figure = board[i][j].getFigure()->print();
			cout << figure;
			cout << " ";
		}
		cout << endl;
	}

	(turn == WHITE) ? cout << "White's turn" << endl : 
		cout << "Black's turn" << endl;
		cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
			
}

void Board::readMove()
{
	string move;
	cin >> move;
	int startX = charToInt(move[0]); 
	int startY = charToInt(move[1]);
	int destinationX = charToInt(move[2]);
	int destinationY = charToInt(move[3]);
	
	if(isSquareOnBoard(startX, startY) &&
	   isSquareOnBoard(destinationX, destinationY))
	{
		// cout << " --------- \n";
		// cout << "readMove()\n";
		// cout << "start[" << startX << "][" << startY << "]" << endl;
		// cout << "dest [" << destinationX << "][" << destinationY << "]" << endl;

		// cout << "board[" << startX << "][" << startY << "]: [" << board[startX][startY].getX() << ", " << board[startX][startY].getY() << "]" << endl;
		// cout << "board[" << destinationX << "][" << destinationY << "]: [" << board[destinationX][destinationY].getX() << ", " << board[destinationX][destinationY].getY() << "]" << endl;

		setStart(&board[startX][startY]);
		setDestination(&board[destinationX][destinationY]);

		// cout << "start=board[" << start->getX() << "][" << start->getY() << "]" << endl;
		// cout << "dest =board[" << destination->getX() << "][" << destination->getY() << "]" << endl;
		// cout << " --------- \n";
	}
	else
	{	///fix this
		cout << "Setting nullptr for start and destination" << endl;
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
	lastTakenFigure = destination->getType();
	
	int saveDestX = destination->getX();
	int saveDestY = destination->getY();
	int saveStartX = start->getX();
	int saveStartY = start->getY();

	start->setFigurePosition(saveDestX, saveDestY);
	destination->setFigure(start->getFigure());
	EmptyFigure *emptyFig = new EmptyFigure(EMPTY, NONE, saveStartX, saveStartY);
	start->setFigure(emptyFig);
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

	cout << "Figure is : " << start->getColor() << " color " << endl;

	if(!isCorrectFigure) 
	{
		cout << "You don't have figure there!" << endl;
	}

	return isCorrectFigure;
}

bool Board::canLand()
{
	bool validLand = (start->getColor() != destination->getColor());
	// cout << "canLand()\n";
	// cout << "Start_Square: coords=(" << start->getX() << ", " << start->getY() 
	// 	 << ") color=" << start->getColor() << " type=" << start->getType() << endl;
	// cout << "Dest_Square:  coords=(" << destination->getX() << ", " << destination->getY() 
	// 	 << ") color=" << destination->getColor() << " type=" << destination->getType() << endl;

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
	bool movesOneHorizontally = abs(start->getY() - destination->getY()) == 1;

	if(!(isPawnMove && movesOneHorizontally))
	{
		return false;
	}

	int xMovement = destination->getX() - start->getX();

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

	for(pair<int, int> &p : path)
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
	bool isHorizontal = (start->getX() == destination->getX());

	return isPawn && isHorizontal;
}

vector<pair<int, int>> Board::generatePath()
{
	int destinationX = destination->getX();
	int destinationY = destination->getY();
	Figure* startFigure = start->getFigure();

	vector<pair<int, int>> path = startFigure->generatePath(destinationX, destinationY);

	return path;
}

void Board::switchPlayerTurn()
{
	(turn == BLACK) ? turn = WHITE : turn = BLACK;
}