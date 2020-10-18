#include <iostream>
#include "Declarations.h"
#include "Player.h"
#include "Settings.h"

void SetShip(int** board, int x, int y, int ship_id)
{
	board[x][y] = ship_id;
}

bool CheckAndSet(int ** board, int ship_blocks, int ship_id, char orientation, Coordinate coordinate)
{
	if (orientation == 'h')
	{
		if (!(coordinate.y + ship_blocks > 10 || CheckOverlap(board, orientation, coordinate, ship_blocks)))
		{
			int counter = 0;

			while (counter < ship_blocks)
			{
				SetShip(board, coordinate.x, coordinate.y++, ship_id);
				counter++;
			}
			return true;
		}

	}
	else
	{
		if (!(coordinate.x + ship_blocks > 10 || CheckOverlap(board, orientation, coordinate, ship_blocks)))
		{
			int counter = 0;

			while (counter < ship_blocks)
			{
				SetShip(board, coordinate.x++, coordinate.y, ship_id);
				counter++;
			}
			return true;
		}
	}

	return false;
}

void PlacePlayerShip(Board board, int ship_blocks, int ship_id, bool inputDevices)
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
		if (inputDevices)
		{
			GetShipCoordinate(board, orientation, coordinate, ship_blocks, ship_id);
		}
		else
		{
			GetOrientation(orientation);
			GetCoordinates(coordinate);
		}
		
		if (!CheckAndSet(board.board, ship_blocks, ship_id, orientation, coordinate))
		{
			caret_position = GetConsoleCaretPosition(hConsoleOUT);

			if (caret_position.Y >= max_coordinates.Y)
			{
				ClearConsoleArea({ 0, 0 }, { 30, 25 });
				SetConsoleCursorPosition(hConsoleOUT, { 0 , 0 });
			}

			std::cout << "\nTry Again!\n\n";
			continue;
		}

		return;
	}

	system("CLS");
}

void PlaceAIShip(int** board, int ship_blocks, int ship_id)
{
	Coordinate coordinate;
	static int arr[2]{};
	while (true)
	{
		char orientation;
		if (ship_id <= 3)
		{
			if (arr[0] > arr[1])
			{
				orientation = 'v';
			}
			else
			{
				orientation = 'h';
			}
		}
		else
		{
			orientation = (Draw()) ? 'h' : 'v';
		}

		coordinate.x = rand() % 10;
		coordinate.y = rand() % 10;

		if (!CheckAndSet(board, ship_blocks, ship_id, orientation, coordinate))
		{
			continue;
		}

		if (orientation == 'h')
		{
			arr[0]++;
		}
		else
		{
			arr[1]++;
		}

		if (ship_id == DESTROYER)
			arr[0] = 0; arr[1] = 0;
		return;
	}
}