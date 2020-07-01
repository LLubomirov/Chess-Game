#include "square.h"
#include "./Figures/king.h"
#include "./Figures/queen.h"
#include "./Figures/bishop.h"
#include "./Figures/rook.h"
#include "./Figures/knight.h"
#include "./Figures/pawn.h"
#include "./Figures/empty_figure.h"

#ifndef __BOARD_H
#define __BOARD_H
#define BOARD_ROWS 8
#define BOARD_COLUMNS 8

class Board
{
public:
	Board();

	Square getSquare(pair<int, int>) const;
	Figure *getFigure(pair<int, int>) const;
	FigureColor getColor(pair<int, int>) const;
	FigureType getType(pair<int, int>) const;

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