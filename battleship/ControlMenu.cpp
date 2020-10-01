#include <iostream>
#include "Declarations.h"
#include <conio.h>


void ControlMenu(char ** options, short size, short& selected)
{
	while (true)
	{
		system("CLS");
		PrintMenu(options, size, selected - 1);

		int key = _getch();

		if (key == 224)
		{
			switch (_getch())
			{
			case KEY_UP:
			{
				if (selected > 1)
					selected--;
			}
			break;
			case KEY_DOWN:
			{
				if (selected < size)
					selected++;
			}
			break;
			}
		}
		else if (key == 13)
		{
			return;
		}
	}
}