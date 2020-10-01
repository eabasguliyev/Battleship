#include <iostream>
#include "Declarations.h"


void PlaceTheShip(int ** board, int ship_blocks, int ship_id)
{
	int x, y;

	char orientation;

	while (true)
	{
		GetOrientation(orientation);

		GetCoordinates(x, y);

		if (orientation == 'h')
		{
			if (y + ship_blocks > 10 || CheckOverlap(board, orientation, x, y, ship_blocks))
			{
				std::cout << "\nTry again!\n";
				continue;
			}
			int counter = 0;

			while (counter < ship_blocks)
			{
				board[x][y++] = ship_id;
				counter++;
			}
		}
		else
		{
			if (x + ship_blocks > 10 || CheckOverlap(board, orientation, x, y, ship_blocks))
			{
				std::cout << "\nTry again!\n";
				continue;
			}
			int counter = 0;

			while (counter < ship_blocks)
			{
				board[x++][y] = ship_id;
				counter++;
			}
		}
		return;
	}
}