#ifndef __BOARD_H
#define __BOARD_H

#include "square.h"
#include "./Figures/king.h"
#include "./Figures/queen.h"
#include "./Figures/bishop.h"
#include "./Figures/rook.h"
#include "./Figures/knight.h"
#include "./Figures/pawn.h"

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
	void printBoard();
	
private:
	friend class ChessGame;
	friend class ExtendedBoard; 
	friend class ExtendedChessGame;

	void setBoard();
	void setFigureOn(Figure*, pair<int, int>); 

	Square board[BOARD_ROWS][BOARD_COLUMNS];
};

#include "board.cpp"

#endif