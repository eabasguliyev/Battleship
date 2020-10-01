#include <iostream>
#include <Windows.h>
#include "Declarations.h"

int PrintMenu(char** menu, const int size, const int selected_index)
{
	SetCenterY();
	for (size_t i = 0; i < size; i++)
	{
		SetCenterX();
		if (selected_index == i)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			std::cout << menu[i] << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			continue;
		}
		std::cout << menu[i] << std::endl;
	}
	return 0;
}