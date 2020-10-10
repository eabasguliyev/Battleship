#include <Windows.h>
#include "Declarations.h"

void StartScreen()
{
	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hConsoleOUT, { 43, 12 });
	TypingEffect("Battleship game starting...");
	Sleep(1000);
}