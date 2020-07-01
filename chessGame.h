#ifndef __CHESS_GAME_H
#define __CHESS_GAME_H

#include "board.cpp"

class ChessGame : public Board
{
public:
    ChessGame();
    void play();

protected:
    Board board;
    FigureType lastTakenFigure = EMPTY;
    FigureColor turn = WHITE;
    pair<int, int> start;
    pair<int, int> destination;
    
    void playOneChessGame();
    void setChessGame();
    bool thereIsWinner() const;
    void performMove();
    void readMove();
    bool isValidMove() const;
    bool inputInBounds() const;
    bool isSquareOnBoard(int, int) const;
    bool figureOnTurn() const;
    bool landEmptyOrEnemy() const;
    bool isReachable() const;
    bool isValidPawnAttack() const;
    std::vector<std::pair<int, int>> generateMovePath() const;
    void moveFigure() ;
    void switchTurn();
    void announceWinner() const;
};

#include "chessGame.cpp"

#endif