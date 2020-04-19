#include "board.h"

void Board::printBoard() {
	cout << "   y: 0  1  2  3  4  5  6  7 " << endl << "x:" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << " " << i << "   ";
		for (int j = 0; j < 8; j++)
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
	string move;
	int x1, x2, y1, y2;
	bool stop = false;
	while (!stop)
	{
		(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
		cin >> move;
		x1 = move[0] - 48; 
		y1 = move[1] - 48;
		x2 = move[2] - 48;
		y2 = move[3] - 48;
		if (getSquare(x1, y1)->getColor() == turn)
		{
			if (makeMove(&board[x1][y1], &board[x2][y2]) == false)
			{
				cout << "Invalid move, try again." << endl;
			}
			else
			{
				if (getSquare(x2, y2)->getFigure()->getType() == KING)
				{
					if (getSquare(x1, y1)->getColor() == WHITE)
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
				board[x1][y1].setPosition(x2, y2);
				board[x2][y2].setFigure(board[x1][y1].getFigure());
				board[x1][y1].setFigure(new EmptyFigure(EMPTY, NONE, x1, y1));
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

bool Board::validPositionOnBoard(Square *position)
{
	int positionX = position->getX();
	int positionY = position->getY();
	return  positionX >= 0 && 
			positionX < 8 &&
			positionY >= 0 && 
			positionY < 8;
}

bool Board::isValidMove(Square *start, Square *destination)
{
	FigureColor startColor = start->getColor();
	vector<pair<int, int>> path = start->getFigure()->generatePathOfPairs(destination->getX(), destination->getY());
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

bool Board::makeMove(Square *start, Square *destination) 
{
	if(!(validPositionOnBoard(start) && validPositionOnBoard(destination)))
	{
		cout << "One of your inputs was our of bounds" << endl;
		return false;
	}

	if(start->getColor() == destination->getColor() && destination->getColor() != NONE)
	{
		cout << "Invalid move: cannot land on your own piece: " << endl;
		return false;
	}

	if(start->getColor() != turn)
	{
		cout << "You do not have a piece there" << endl;
		return false;
	}
	
	if(start->getFigure()->getType() == PAWN && abs(start->getX() - destination->getX()) == 1)
	{
		if ((start->getFigure()->isWhite()) ? 
				destination->getFigure()->isBlack() && destination->getY() - start->getY() == 1 : 
				destination->getFigure()->isWhite() && destination->getY() - start->getY() == -1)
		{
			return true;
		}
	}

	if(isValidMove(start, destination))
	{
		return true;
	}


	return false;
}

