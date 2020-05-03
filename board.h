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
	void doMove();
	int charToInt(char input);
	bool isCorrectMove();
	bool isCorrectInput();
	bool isValidPositionOnBoard(Square *position);
	bool isPawn(Square *square);
	bool isPawnDiagonalMove();
	bool isBlackPawnAttack(Figure *startFigure, Figure *destinationFigure);
	bool isMoveLeft(Figure *startFigure, Figure *destinationFigure);
	bool isWhitePawnAttack(Figure *startFigure, Figure *destinationFigure);
	bool isMoveRight(Figure *startFigure, Figure *destinationFigure);
	bool isValidMove();
	vector<pair<int, int>> generatePath();
	void attackFigure(Square *attacker, Square *attacked);
	void switchPlayerTurn();
};

#endif