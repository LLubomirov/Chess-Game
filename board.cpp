#include "board.h"

Board::Board()
{
	for(int i = 0; i < BOARD_ROWS; ++i)
	{
		for(int j = 0; j < BOARD_COLUMNS; ++j)
		{
			this->board[i][j].setFigure(new EmptyFigure (EMPTY, NONE, i, j));
		}
	}
}


void Board::printBoard() 
{
	cout << "   y: 0  1  2  3  4  5  6  7 " << endl << "x:" << endl;
	for (int i = 0; i < BOARD_ROWS; i++)
	{
		cout << " " << i << "   ";
		for (int j = 0; j < BOARD_COLUMNS; j++)
		{
			cout << " ";
			char figure = board[i][j].getFigure()->printFigureOnBoard();
			cout << figure;
			cout << " ";
		}
		cout << endl;
	}
}

bool Board::doMove() 
{
	bool stop = false;
	while (!stop)
	{
		(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
		string move;
		cin >> move;
		int startX = charToInt(move[0]); 
		int startY = charToInt(move[1]);
		int destinationX = charToInt(move[2]);
		int destinationY = charToInt(move[3]);
		if (board[startX][startY].getFigureColor() == turn)
		{
			if (isPossibleMove(&board[startX][startY], &board[destinationX][destinationY]) == false)
			{
				cout << "Invalid move, try again." << endl;
			}
			else
			{
				if (board[destinationX][destinationY].getFigure()->getType() == KING)
				{
					if (board[startX][startY].getFigureColor() == WHITE)
					{
						cout << "WHITE WINS" << endl;
						return false;
					}
					else
					{
						cout << "BLACK WINS" << endl;
						return false;
					}
				}
				board[startX][startY].setFigurePosition(destinationX, destinationY);
				board[destinationX][destinationY].setFigure(board[startX][startY].getFigure());
				board[startX][startY].setFigure(new EmptyFigure(EMPTY, NONE, startX, startY));
				stop = true;
			}
		}
		else
			cout << "That's not your piece. Try again." << endl;
	}

	if (turn == BLACK)
		turn = FigureColor::WHITE;
	else
		turn = FigureColor::BLACK;

	return true;

}

int Board::charToInt(char input)
{
	int num = input - 48;
	return num;
}

void Board::setBoard()
{
	this->turn = WHITE;
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

bool Board::playGame()
{
	system("cls");
	printBoard();
	return doMove();
}

bool Board::isValidPositionOnBoard(Square *position)
{
	int positionX = position->getFigureX();
	int positionY = position->getFigureY();
	return  positionX >= 0 && 
			positionX < BOARD_ROWS &&
			positionY >= 0 && 
			positionY < BOARD_COLUMNS;
}

bool Board::isValidMove(Square *start, Square *destination)
{
	vector<pair<int, int>> path = generatePath(start, destination);
	bool isValid = !path.empty();
	if(isValid)
	{
		path.pop_back();
	}
	for(pair<int, int> &p : path)
	{
		if(board[p.first][p.second].getFigureColor() != NONE)
		{
			isValid = false;
		}
	}

	return isValid;
}

vector<pair<int, int>> Board::generatePath(Square *start, Square *destination)
{
	int destinationX = destination->getFigureX();
	int destinationY = destination->getFigureY();
	Figure* startFigure = start->getFigure();
	vector<pair<int, int>> path = startFigure->generatePathOfPairs(destinationX, destinationY);

	return path;
}

bool Board::isPossibleMove(Square *start, Square *destination) 
{
	if(isIncorrectInput(start, destination))
	{
		return false;
	}
	
	if(isPawn(start) && abs(start->getFigureX() - destination->getFigureX()) == 1)
	{
		return isPawnDiagonalMove(start, destination);
	}

	if(isValidMove(start, destination))
	{
		return true;
	}
	return false;
}

bool Board::isIncorrectInput(Square *start, Square *destination)
{
	if(!(isValidPositionOnBoard(start) && isValidPositionOnBoard(destination)))
	{
		cout << "One of your inputs was our of bounds" << endl;
		return true;
	}

	if(start->getFigureColor() != turn)
	{
		cout << "You do not have a piece there" << endl;
		return true;
	}

	if(start->getFigureColor() == destination->getFigureColor() && destination->getFigureColor() != NONE)
	{
		cout << "Invalid move: cannot land on your own piece: " << endl;
		return true;
	}

	return false;
}

bool Board::isPawn(Square *square)
{
	Figure *figure = square->getFigure();
	return figure->getType() == PAWN;
}

bool Board::isPawnDiagonalMove(Square *start, Square *destination)
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

bool Board::isWhitePawnAttack(Figure *startFigure, Figure *destinationFigure)
{
	return (startFigure->isWhite() && 
		 	destinationFigure->isBlack() && 
			isMoveRight(startFigure, destinationFigure));
}

bool Board::isMoveRight(Figure *startFigure, Figure *destinationFigure)
{
	return destinationFigure->getFigureY() - startFigure->getFigureY() == 1;
}

bool Board::isMoveLeft(Figure *startFigure, Figure *destinationFigure)
{
	return destinationFigure->getFigureY() - startFigure->getFigureY() == -1;
}