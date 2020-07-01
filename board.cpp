#include "board.h"

Board::Board()
{
	for(int i = 0; i < BOARD_ROWS; ++i)
	{
		for(int j = 0; j < BOARD_COLUMNS; ++j)
		{
			setFigureOn(new EmptyFigure (EMPTY, NONE), {i, j});
		}
	}
}

Square Board::getSquare(pair<int, int> position)
{
	return this->board[position.first][position.second];
}

Figure* Board::getFigure(pair<int, int> start)
{
	return board[start.first][start.second].getFigure();
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

void Board::printBoard() 
{
	system("cls");
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
}

bool Board::isSquareOnBoard(int x, int y)
{
	return  x >= 0 && 
			x < BOARD_ROWS &&
			y >= 0 && 
			y < BOARD_COLUMNS;
}