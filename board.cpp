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

	this->start = &board[0][0];
	this->destination = &board[0][0];
}

void Board::setBoard()
{
	board[0][0].setFigure(new Rook  (ROOK,   WHITE, 0, 0));
	board[1][0].setFigure(new Knight(KNIGHT, WHITE, 1, 0));
	board[2][0].setFigure(new Bishop(BISHOP, WHITE, 2, 0));
	board[3][0].setFigure(new Queen (QUEEN,  WHITE, 3, 0));
	board[4][0].setFigure(new King  (KING,   WHITE, 4, 0));
	board[5][0].setFigure(new Bishop(BISHOP, WHITE, 5, 0));
	board[6][0].setFigure(new Knight(KNIGHT, WHITE, 6, 0));
	board[7][0].setFigure(new Rook  (ROOK,   WHITE, 7, 0));

	board[0][7].setFigure(new Rook  (ROOK,   BLACK, 0, 7));
	board[1][7].setFigure(new Knight(KNIGHT, BLACK, 1, 7));
	board[2][7].setFigure(new Bishop(BISHOP, BLACK, 2, 7));
	board[3][7].setFigure(new Queen (QUEEN,  BLACK, 3, 7));
	board[4][7].setFigure(new King  (KING,   BLACK, 4, 7));
	board[5][7].setFigure(new Bishop(BISHOP, BLACK, 5, 7));
	board[6][7].setFigure(new Knight(KNIGHT, BLACK, 6, 7));
	board[7][7].setFigure(new Rook  (ROOK,   BLACK, 7, 7));

	for (int i = 0; i < 8; i++)
	{
		board[i][1].setFigure(new Pawn(PAWN, WHITE, i, 1));
		board[i][6].setFigure(new Pawn(PAWN, BLACK, i, 6));
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

void Board::playGame()
{
	setBoard();
	while(!thereIsWinner())
	{
		printBoard(); 
		readMove();
		validateMove();
		moveFigure(); 
		switchPlayerTurn();
	}

	switchPlayerTurn();
	(turn == WHITE) ? cout << "WHITE WINS\n" : cout << "BLACK WINS\n";
}

bool Board::thereIsWinner()
{
	return lastTakenFigure == KING;
}

void Board::printBoard() 
{
	system("cls");
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

	setStart(&board[startX][startY]);
	setDestination(&board[destinationX][destinationY]);
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
	if (start->getColor() == turn && start->getColor() != destination->getColor()) 
	{
		if(!inputInBounds()) 
		{
			cout << "One of your inputs was out of bounds!" << endl;

			return false;
		}

		
		if(isPawn(start) && abs(start->getX() - destination->getX()) > 0) 
		{
			return isPawnAttack();
		}

		if(!pathIsClear())
		{
			cout << "Something is blocking your path to the destination square!" << endl;

			return false;
		}

		else
		{
			return true;
		}
	}

	else
	{
		cout << "That's not your figure!" << endl;

		return false;
	}
}

bool Board::inputInBounds()
{
	return isSquareOnBoard(start) &&
		   isSquareOnBoard(destination);
}


bool Board::isSquareOnBoard(Square *position)
{
	int positionX = position->getX();
	int positionY = position->getY();
	
	return  positionX >= 0 && 
			positionX < BOARD_ROWS &&
			positionY >= 0 && 
			positionY < BOARD_COLUMNS;
}

bool Board::isPawn(Square *square)
{
	Figure *figure = square->getFigure();

	return figure->getType() == PAWN;
}

bool Board::isPawnAttack()
{
	Figure *startFigure = start->getFigure(); 
	Figure *destinationFigure = destination->getFigure(); 
	
	return isBlackPawnAttack(startFigure, destinationFigure) || 
		   isWhitePawnAttack(startFigure, destinationFigure);
}

bool Board::isBlackPawnAttack(Figure *startFigure, Figure *destinationFigure)
{
	return (startFigure->isBlack() && 
		destinationFigure->isWhite() 
		&& isMoveLeft(startFigure, destinationFigure));
}

bool Board::isMoveLeft(Figure *startFigure, Figure *destinationFigure)
{
	return destinationFigure->getY() - startFigure->getY() == -1;
}

bool Board::isWhitePawnAttack(Figure *startFigure, Figure *destinationFigure)
{
	return (startFigure->isWhite() && 
		destinationFigure->isBlack() && 
		isMoveRight(startFigure, destinationFigure));
}

bool Board::isMoveRight(Figure *startFigure, Figure *destinationFigure)
{
	return destinationFigure->getY() - startFigure->getY() == 1;
}

bool Board::pathIsClear()
{
	vector<pair<int, int>> path = generatePath();
	bool isValid = !path.empty();

	if(isValid)
	{
		path.pop_back();
	}

	for(pair<int, int> &p : path)
	{
		if(board[p.first][p.second].getColor() != NONE)
		{
			isValid = false;
		}
	}

	return isValid;
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