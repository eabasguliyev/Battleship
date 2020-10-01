#include <iostream>
#include "Player.h"
#include "Declarations.h"


int main()
{
	SetCenterY();
	SetCenterX();
	StartScreen();

	while (true)
	{
		if (GameModeScreen() == SINGLEPLAYER)
		{
			system("CLS");

			short difficulty = GetDiff();

			system("CLS");

			Game(difficulty);
		}
		else
		{
			system("CLS");
			Game();
		}
	}
	std::cin.get();
}