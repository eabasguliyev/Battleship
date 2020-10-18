#include <iostream>
#include "Player.h"
#include <cstring>

void GetOrientation(char& orientation)
{
	do
	{
		std::cout << "Orientation: ";
		std::cin >> orientation;
		orientation = tolower(orientation);
	} while (orientation != 'h' && orientation != 'v');
}


void GetCoordinates(Coordinate & coordinate)
{
	char cx, cy;
	do
	{
		std::cout << "x (0 - 9) : ";
		std::cin >> cy;
	} while (int(cy) < 48 || int(cy) > 57);

	do
	{
		std::cout << "y (0 - 9) : ";
		std::cin >> cx;
	} while (int(cx) < 48 || int(cx) > 57);

	coordinate.x = int(cx) - 48;
	coordinate.y = int(cy) - 48;
}

void GetCoordinatesWithMouse(Coordinate & coordinate)
{
	HANDLE hConsoleIN = GetStdHandle(STD_INPUT_HANDLE);

	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	INPUT_RECORD input_record = {};

	unsigned long nRecordsRead = 0;


	SetConsoleMode(hConsoleIN, ENABLE_MOUSE_INPUT);
	int selected = 0;
	bool updateScreen = true;
	while (1)
	{
		ReadConsoleInput(hConsoleIN, &input_record, 1, &nRecordsRead);

		if (input_record.EventType == MOUSE_EVENT)
		{
			Coordinate new_coord;
			new_coord.x = input_record.Event.MouseEvent.dwMousePosition.X;
			new_coord.y = input_record.Event.MouseEvent.dwMousePosition.Y;

			if (new_coord.x % 3 == 0 && new_coord.x >= 24 && new_coord.x <= 51 &&
				new_coord.y >= 9 && new_coord.y <= 18)
			{

				if (input_record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					SetConsoleCursorPosition(hConsoleOUT, { 0, 20 });
					coordinate.x = new_coord.y - 9;
					coordinate.y = new_coord.x / 3 - 8;
					return;
				}
			}
		}
		
	}
}




void PrintSymbol(int x, char orientation, char character)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	printf("%c", character);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}
void PrintShip(HANDLE hConsoleOUT, Coordinate coord, int ship_id, char orientation = 'o')
{
	COORD coordinate;
	coordinate.X = coord.x;
	coordinate.Y = coord.y;
	SetConsoleCursorPosition(hConsoleOUT, coordinate);

	switch (ship_id)
	{
	case DESTROYER:
	{
		PrintSymbol(coordinate.X, orientation, 'D');
	}
	break;
	case SUBMARINE:
	{
		PrintSymbol(coordinate.X, orientation, 'S');
	}
	break;
	case CRUISER:
	{
		PrintSymbol(coordinate.X, orientation, 'C');
	}
	break;
	case BATTLESHIP:
	{
		PrintSymbol(coordinate.X, orientation, 'B');
	}
	break;
	case CARRIER:
	{
		PrintSymbol(coordinate.X, orientation, 'A');
	}
	break;
	default:
		break;
	}
}

void GetShipCoordinate(Board board, char& orient, Coordinate& coordinate, short ship_blocks, short ship_id)
{
	HANDLE hConsoleIN = GetStdHandle(STD_INPUT_HANDLE);

	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	INPUT_RECORD input_record = {};

	unsigned long nRecordsRead = 0;


	SetConsoleMode(hConsoleIN, ENABLE_MOUSE_INPUT);
	bool updateScreen = false;

	bool is_first_coordinate = true;

	Coordinate first_coordinate{};

	short counter = 0;

	Coordinate last_coordinate;

	short ship_block_counter = 0;
	char orientation = ' ';

	while (1)
	{
		ReadConsoleInput(hConsoleIN, &input_record, 1, &nRecordsRead);

		if (counter == ship_blocks)
		{
			orient = orientation;
			coordinate.x = first_coordinate.y - 9;
			coordinate.y = first_coordinate.x / 3 - 15; 
			return;

		}
		if (input_record.EventType == MOUSE_EVENT)
		{
			Coordinate new_coord;
			new_coord.x = input_record.Event.MouseEvent.dwMousePosition.X;
			new_coord.y = input_record.Event.MouseEvent.dwMousePosition.Y;

			if (new_coord.x % 3 == 0 && new_coord.x >= 45 && new_coord.x <= 72 &&
				new_coord.y >= 9 && new_coord.y <= 18)
			{
				SetConsoleCursorPosition(hConsoleOUT, { 0, 13 });

				if (input_record.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					updateScreen = true;
					if (is_first_coordinate)
					{
						first_coordinate.x = new_coord.x;
						first_coordinate.y = new_coord.y;
						is_first_coordinate = false;
						counter++;
						last_coordinate = first_coordinate;

						PrintShip(hConsoleOUT, new_coord, ship_id);
					}
					else
					{
						if (new_coord.y == first_coordinate.y && orientation != 'v')
						{
							if (new_coord.x - 3 == last_coordinate.x)
							{
								orientation = 'h';
								last_coordinate = new_coord;
								counter++;

								PrintShip(hConsoleOUT, new_coord, ship_id, orientation);
							}
						}
						else if (new_coord.x == first_coordinate.x && orientation != 'h')
						{
							if (new_coord.y - 1 == last_coordinate.y)
							{
								orientation = 'v';
								last_coordinate = new_coord;
								counter++;
								PrintShip(hConsoleOUT, new_coord, ship_id, orientation);
							}
						}

					}
				}
				else if (updateScreen)
				{
					board.PrintBoard({ 42,8 });

					orientation = ' ';
					is_first_coordinate = true;
					counter = 0;
					first_coordinate.x = 0;
					first_coordinate.y = 0;
					last_coordinate.x = 0;
					last_coordinate.y = 0;
					updateScreen = false;
				}
			}
			else if (input_record.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED && updateScreen)
			{
				board.PrintBoard({ 42,8 });
				orientation = ' ';
				counter = 0;
				is_first_coordinate = true;
				first_coordinate.x = 0;
				first_coordinate.y = 0;
				last_coordinate.x = 0;
				last_coordinate.y = 0;
				updateScreen = false;
			}
		}

	}
	return;
}