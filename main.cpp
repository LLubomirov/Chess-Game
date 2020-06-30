#include "board.cpp"

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "test_setBoard.cpp"

int main()
{
	// doctest::Context().run();
	// return 0;

	bool newgame = true;
	while(newgame)
	{
		Board b;
		b.playGame();
		cout << "Do you want to play again? (y for yes, anything else for no) ";
		string continuePlaying;
		cin >> continuePlaying;
		if (continuePlaying != "y")
		{
			newgame = false;
		}
	}

	return 0;
}