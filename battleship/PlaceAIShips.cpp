#include <iostream>
#include "Board.h"
#include <time.h>

void PlaceAIShips(int** board, int ship_blocks, int ship_id)
{
	
	
	while(true)
	{
		char orientation = (Draw()) ? 'h' : 'v';

		if (orientation == 'h')
		{
			int x = rand() % 10;
			int y = rand() % (10 - ship_blocks);

			if (!CheckOverlap(board, orientation, x, y, ship_blocks))
			{
				int counter = 0;
				while (counter < ship_blocks)
				{
					SetShip(board, x, y++, ship_id);
					counter++;
				}
				return;
			}
		}
		else
		{
			
			int x = rand() % (10 - ship_blocks);
			int y = rand() % 10;

			if (!CheckOverlap(board, orientation, x, y, ship_blocks))
			{
				int counter = 0;
				while (counter < ship_blocks)
				{
					SetShip(board, x++, y, ship_id);
					counter++;
				}
				return;
			}
		}
		
	}
}