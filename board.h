#include "square.cpp"
#include "king.cpp"
#include "queen.cpp"
#include "bishop.cpp"
#include "rook.cpp"
#include "knight.cpp"
#include "pawn.cpp"
#include "empty_figure.cpp"

#ifndef __BOARD_H
#define __BOARD_H
#define BOARD_ROWS 8
#define BOARD_COLUMNS 8


class Figure;

class Board
{
private:
	Square board[BOARD_ROWS][BOARD_COLUMNS];
	FigureColor turn = WHITE;

	bool makeMove(Square *start, Square *destination);
	bool validPositionOnBoard(Square *position);
	bool isValidMove(Square *start, Square *destination);
	

public:
	void printBoard();

	Board()
	{
		for(int i = 0; i < BOARD_ROWS; ++i)
		{
			for(int j = 0; j < BOARD_COLUMNS; ++j)
			{
				this->board[i][j].setFigure(new EmptyFigure (EMPTY, NONE, i, j));
			}
		}
	}

	Square* getSquare(int x, int y) 
	{
		return &board[x][y];
	}

	void setSquare(Square * s, int x, int y)
	{
		board[x][y]=*s;
	}

	bool playGame();
	void setBoard(); 
	bool doMove(); 
};

#endif