#include <iostream>
#include "Player.h"
#include "Declarations.h"
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include "Settings.h"

void ConsoleScreenSettings()
{
	HANDLE hConsoleIN = GetStdHandle(STD_INPUT_HANDLE);

	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);

	TCHAR consoleNewTitle[MAX_PATH];

	StringCchPrintf(consoleNewTitle, MAX_PATH, TEXT("BATTLESHIP"));

	SetConsoleTitle(consoleNewTitle);

	HWND consoleWindow = GetConsoleWindow();
	MoveWindow(consoleWindow, 500, 58, 895, 518 , TRUE);
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);


	CONSOLE_CURSOR_INFO cursor_info = {};

	cursor_info.bVisible = false;
	cursor_info.dwSize = 1;
	SetConsoleCursorInfo(hConsoleOUT, &cursor_info);
}

int main()
{
	
	Settings gs;
	gs.inputDevices = true;
	ConsoleScreenSettings();
	StartScreen();
	srand(time(NULL));
	while (true)
	{
		short status = MainScreen(gs.inputDevices);
		if (status == 1)
		{
			if (gs.gameMode)
			{
				system("CLS");
				gs.diff = GetDiff(gs.inputDevices);
			}

			system("CLS");
			Game(gs);
		}
		else if (status == 2)
		{
			GameSettings(gs);
		}
		else if (status == 3)
		{
			system("CLS");
			std::cout << "Battleship is a strategy type guessing game for two players. The game supports both multiplayer and singleplayer modes.\n";
			std::cout << "The game consists of 10 out of 10 cells and 5 ships. Carrier is 5 digits, Battleship is 4 digits, \nCruiser and Submarine are 3 digits, and Destroyer is 2 digits.\n";
			std::cout << "When ships are placed in cells, the orientation includes horizontal (h) or vertical (v) directions,\nand x and y include numbers between 0-9.\nThere must be at least 1 empty cell between each type of ship. \nEach cell is equal to one cell of the ship.\n";
			std::cout << "After the game starts, the coordinates are taken with the keyboard or mouse. \nIf any ship has a cell in the given coordinate, you will be asked to guess again.\nOtherwise, your opponent will start guessing.\n";
				
			Wait();
		}
		else
		{
			exit(0);
		}
	}
}