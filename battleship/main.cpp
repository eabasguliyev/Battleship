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
			std::cout << "About\n";
			Wait();
		}
		else
		{
			exit(0);
		}
	}
}