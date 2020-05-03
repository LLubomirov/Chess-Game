#include "board.cpp"

int main()
{
	cout << "   _____ _    _ ______  _____ _____ \n  / ____| |  | |  ____|/ ____/ ____| \n | |    | |__| | |__  | (___| (___  \n | |    |  __  |  __|  \\___  \\___ \\ \n | |____| |  | | |____ ____) |___) | \n  \\_____|_|  |_|______|_____/_____/ \n" << endl;
	cout << "Enter any key to continue" << endl;
	string pressAnyKey;
	cin >> pressAnyKey;

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