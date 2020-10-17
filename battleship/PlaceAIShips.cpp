#include <iostream>
#include "Board.h"
#include "Player.h"
#include <time.h>

void PlaceAIShips(int** board, int ship_blocks, int ship_id)
{
	Coordinate coordinate;
	
	while(true)
	{
		char orientation = (Draw()) ? 'h' : 'v';

		if (orientation == 'h')
		{
			coordinate.x = rand() % 10;
			coordinate.y = rand() % (10 - ship_blocks);

			if (!CheckOverlap(board, orientation, coordinate, ship_blocks))
			{
				int counter = 0;
				while (counter < ship_blocks)
				{
					SetShip(board, coordinate.x, coordinate.y++, ship_id);
					counter++;
				}
				return;
			}
		}
		else
		{
			
			coordinate.x = rand() % (10 - ship_blocks);
			coordinate.y = rand() % 10;

			if (!CheckOverlap(board, orientation, coordinate, ship_blocks))
			{
				int counter = 0;
				while (counter < ship_blocks)
				{
					SetShip(board, coordinate.x++, coordinate.y, ship_id);
					counter++;
				}
				return;
			}
		}
		
	}
}