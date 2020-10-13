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

	CONSOLE_CURSOR_INFO cursor_info = {};

	cursor_info.bVisible = false;
	cursor_info.dwSize = 0;

	SetConsoleCursorInfo(hConsoleOUT, &cursor_info);

	TCHAR consoleNewTitle[MAX_PATH];

	StringCchPrintf(consoleNewTitle, MAX_PATH, TEXT("BATTLESHIP"));

	SetConsoleTitle(consoleNewTitle);

	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

int main()
{
	ConsoleScreenSettings();

	Settings gs;
	gs.inputDevices = false;
	
	StartScreen();
	//SoundEffects(0);

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
		else
			exit(0);
	}
}