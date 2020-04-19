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

	bool isPossibleMove(Square *start, Square *destination);
	bool isIncorrectInput(Square *start, Square *destination);
	bool isValidPositionOnBoard(Square *position);
	bool isValidMove(Square *start, Square *destination);
	bool isPawnDiagonalMove(Square *start, Square *destination);
	bool isWhitePawnAttack(Figure *startFigure, Figure *destinationFigure);
	bool isBlackPawnAttack(Figure *startFigure, Figure *destinationFigure);
	bool isMoveRight(Figure *startFigure, Figure *destinationFigure);
	bool isMoveLeft(Figure *startFigure, Figure *destinationFigure);
	bool isPawn(Square *square);

public:
	Board();
	bool playGame();

	void printBoard();
	void setBoard(); 
	bool doMove(); 
	int charToInt(char input);
	vector<pair<int, int>> generatePath(Square *start, Square *destination);
};

#endif