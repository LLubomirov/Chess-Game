#include "chessGame.h"

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "test_setBoard.cpp"
#include "test_king.cpp"
#include "test_figure.cpp"

int main()
{
	// uncomment to start unit tests
	doctest::Context().run();

	// ChessGame chessGame;
	// chessGame.play();

	return 0;
}