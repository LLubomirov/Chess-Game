#include "chessGame.h"

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "./Unit_Tests/test_chessGame.cpp"
#include "./Unit_Tests/test_board.cpp"
#include "./Unit_Tests/test_square.cpp"
#include "./Unit_Tests/test_figure.cpp"
#include "./Unit_Tests/test_king.cpp"
#include "./Unit_Tests/test_queen.cpp"
#include "./Unit_Tests/test_bishop.cpp"
#include "./Unit_Tests/test_knight.cpp"
#include "./Unit_Tests/test_rook.cpp"
#include "./Unit_Tests/test_pawn.cpp"

int main()
{
	// uncomment to start unit tests
	// doctest::Context().run();

	ChessGame chessGame;
	chessGame.play();

	return 0;
}