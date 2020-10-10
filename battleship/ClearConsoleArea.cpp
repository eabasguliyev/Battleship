#include <Windows.h>
#include <iostream>

void ClearConsoleArea(COORD pos1, COORD pos2)
{
	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOUT, { 0 , 0 });
	for (size_t i = pos1.Y; i < pos2.Y; i++)
	{
		for (size_t j = pos1.X; j < pos2.X; j++)
		{
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
}