#include <iostream>
#include <Windows.h>
#include "Declarations.h"

void PrintMenu(char** options, int size, int selected)
{
	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordinate = { 50, 10 };
	for (size_t i = 0; i < size; i++)
	{
		SetConsoleCursorPosition(hConsoleOUT, coordinate);
		if (i == selected)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTRED);
			std::cout << i + 1 << ". " << options[i] << std::endl;;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		}
		else
		{
			std::cout << i + 1 << ". " << options[i] << std::endl;;
		}
		coordinate.Y++;
	}
}