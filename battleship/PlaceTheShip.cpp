#include <iostream>
#include "Declarations.h"
#include "Player.h"

void SetShip(int** board, int x, int y, int ship_id)
{
	board[x][y] = ship_id;
}

void CheckAndSet(int ** board, int ship_blocks, int ship_id, char orientation, Coordinate coordinate)
{
	if (orientation == 'h')
	{
		if (!(coordinate.y + ship_blocks > 10 || CheckOverlap(board, orientation, coordinate, ship_blocks)))
		{
			int counter = 0;

			while (counter < ship_blocks)
			{
				//board[x][y++] = ship_id;
				SetShip(board, coordinate.x, coordinate.y++, ship_id);
				counter++;
			}
			return;
		}

	}
	else
	{
		if (!(coordinate.x + ship_blocks > 10 || CheckOverlap(board, orientation, coordinate, ship_blocks)))
		{
			int counter = 0;

			while (counter < ship_blocks)
			{
				//board[x++][y] = ship_id;
				SetShip(board, coordinate.x++, coordinate.y, ship_id);
				counter++;
			}
			return;
		}
	}
}

void PlaceTheShip(int ** board, int ship_blocks, int ship_id)
{
	Coordinate coordinate;
	char orientation;

	COORD max_coordinates = { 30, 20 };
	COORD caret_position;
	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hConsoleOUT, { 0 , 0 });

	std::cout << "Add ";
	switch (ship_id)
	{
	case DESTROYER:
		std::cout << "Destroyer";
		break;
	case SUBMARINE:
		std::cout << "Submarine";
		break;
	case CRUISER:
		std::cout << "Cruiser";
		break;
	case BATTLESHIP:
		std::cout << "Battleship";
		break;
	case CARRIER:
		std::cout << "Carrier";
		break;
	default:
		break;
	}
	std::cout << std::endl;

	while (true)
	{
		GetOrientation(orientation);

		GetCoordinates(coordinate);

		if (orientation == 'h')
		{
			if (!(coordinate.y + ship_blocks > 10 || CheckOverlap(board, orientation, coordinate, ship_blocks)))
			{
				int counter = 0;

				while (counter < ship_blocks)
				{
					//board[x][y++] = ship_id;
					SetShip(board, coordinate.x, coordinate.y++, ship_id);
					counter++;
				}
				return;
			}

		}
		else
		{
			if (!(coordinate.x + ship_blocks > 10 || CheckOverlap(board, orientation, coordinate, ship_blocks)))
			{
				int counter = 0;

				while (counter < ship_blocks)
				{
					//board[x++][y] = ship_id;
					SetShip(board, coordinate.x++, coordinate.y, ship_id);
					counter++;
				}
				return;
			}
		}

		caret_position = GetConsoleCaretPosition(hConsoleOUT);

		if (caret_position.Y >= max_coordinates.Y)
		{
			ClearConsoleArea({ 0, 0 }, { 30, 25 });
			SetConsoleCursorPosition(hConsoleOUT, { 0 , 0 });
		}

		std::cout << "\nTry Again!\n\n";
	}

	system("CLS");
}