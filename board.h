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
public:
	void playGame();
	Board();

protected:
	Square board[BOARD_ROWS][BOARD_COLUMNS];
	FigureColor turn = WHITE;
	FigureType lastTakenFigure = EMPTY; 
	pair<int, int> startCoords;
	pair<int, int> destCoords;

	Square getSquare(pair<int, int>);
	FigureColor getColor(pair<int, int>);
	FigureType getType(pair<int, int>);
	void setBoard(); 
	void setFigureOn(Figure*, pair<int, int>);
	bool thereIsWinner();
	void printBoard();
	void performMove();
	void readMove();
	void moveFigure();
	int charToInt(char);
	bool isValidMove();
	bool inputInBounds();
	bool isSquareOnBoard(int, int);
	bool figureOnTurn();
	bool canLandOn();
	bool isReachable();
	bool isPawnAttack();
	bool isRegularMove();
	bool isPawnHorizontal();
	vector<pair<int, int>> generatePath();
	void switchPlayerTurn();
};

#endif