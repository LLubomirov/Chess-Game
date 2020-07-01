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

class Board
{
public:
	Board();

	Square getSquare(pair<int, int>);
	Figure *getFigure(pair<int, int>);
	FigureColor getColor(pair<int, int>);
	FigureType getType(pair<int, int>);

	void playGame();
	void printBoard();
	bool isSquareOnBoard(int, int); 
	
protected:
	friend class ChessGame;

	Square board[BOARD_ROWS][BOARD_COLUMNS];

	void setBoard();
	void setFigureOn(Figure*, pair<int, int>); // extremely important
};
#endif