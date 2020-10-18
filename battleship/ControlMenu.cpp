#include <iostream>
#include "Declarations.h"
#include <conio.h>

short MenuInputWithMouse(char** options, int size)
{
	HANDLE hConsoleIN = GetStdHandle(STD_INPUT_HANDLE);

	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	INPUT_RECORD input_record = {};

	unsigned long nRecordsRead = 0;

	COORD coordinate = { 50, 10 };

	SetConsoleMode(hConsoleIN, ENABLE_MOUSE_INPUT);
	int selected = 0;
	bool updateScreen = true;
	while (1)
	{
		if (updateScreen)
			PrintMenu(options, size, selected - 1);

		ReadConsoleInput(hConsoleIN, &input_record, 1, &nRecordsRead);

		if (input_record.EventType == MOUSE_EVENT)
		{
			int x = input_record.Event.MouseEvent.dwMousePosition.X;
			int y = input_record.Event.MouseEvent.dwMousePosition.Y;

			if (y >= coordinate.Y && y < (coordinate.Y + size))
			{
				if (x >= coordinate.X && x < coordinate.X + MENU_ITEM_SIZE)
				{
					updateScreen = true;
					selected = y % coordinate.Y + 1;
					if (input_record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						return selected;
					}
				}
			}
			else
			{
				updateScreen = false;
				selected = 0;
			}
		}
		SetConsoleCursorPosition(hConsoleOUT, { 0,13 });
	}
}

short MenuInputWithKeyboard(char ** options, short size)
{
	short selected = 1;
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
			return selected;
		}
	}
}