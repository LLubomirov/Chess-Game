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

private:
	Square board[BOARD_ROWS][BOARD_COLUMNS];
	FigureColor turn = WHITE;
	FigureType lastTakenFigure = EMPTY; 
	Square *start;
	Square *destination;

	void setBoard(); 
	void setStart(Square*);
	void setDestination(Square*);
	bool thereIsWinner();
	void printBoard();
	void readMove();
	void validateMove();  
	void moveFigure();
	int charToInt(char);
	bool isValidMove();
	bool inputInBounds();
	bool isSquareOnBoard(int, int);
	bool figureOnTurn();
	bool canLand();
	bool isReachable();
	bool isPawnAttack();
	bool isRegularMove();
	bool isPawnHorizontal();
	vector<pair<int, int>> generatePath();
	void switchPlayerTurn();
};

#endif