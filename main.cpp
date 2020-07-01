#include "chessGame.cpp"

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "test_setBoard.cpp"

int main()
{
	// uncomment to start unit tests
	// doctest::Context().run();

	ChessGame chessGame;
	chessGame.play();

	return 0;
}