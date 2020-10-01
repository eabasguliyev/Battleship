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
		short status = GameModeScreen();
		if (status == 1)
		{
			system("CLS");

			short difficulty = GetDiff();

			system("CLS");

			Game(difficulty);
		}
		else if (status == 2)
		{
			system("CLS");
			Game();
		}
		else
			exit(0);
	}
}