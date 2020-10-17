#include <iostream>
#include "Board.h"
#include "Player.h"
#include <time.h>

void PlaceAIShips(int** board, int ship_blocks, int ship_id)
{
	Coordinate coordinate;
	static int arr[2]{};
	while(true)
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
		
		if (CheckAndSet(board, ship_blocks, ship_id, orientation, coordinate))
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