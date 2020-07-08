#ifndef __BOARD_H
#define __BOARD_H

#include "square.h"
#include "./Figures/king.h"
#include "./Figures/queen.h"
#include "./Figures/bishop.h"
#include "./Figures/rook.h"
#include "./Figures/knight.h"
#include "./Figures/pawn.h"
#include "./Figures/empty_figure.h"

#define BOARD_ROWS 8
#define BOARD_COLUMNS 8

class Board : private Square
{
public:
	Board();

	Square getSquare(pair<int, int>) const;
	Figure *getFigure(pair<int, int>) const;
	FigureColor getColor(pair<int, int>) const;
	FigureType getType(pair<int, int>) const;
	void printBoard();
	
private:
	Square board[BOARD_ROWS][BOARD_COLUMNS];

	friend class ExtendBoard;
	friend class ChessGame;

	void setBoard();
	void setFigureOn(Figure*, pair<int, int>); 
};
#endif