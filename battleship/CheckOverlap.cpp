#include <iostream>
#include "Player.h"

bool CheckOverlap(int ** board, char orientation, Coordinate coordinate, int ship_blocks)
{
	
	ship_blocks++;
	int counter = 0;

	if (orientation == 'h')
	{
		if (coordinate.y > 0)
		{
			ship_blocks++;
			coordinate.y--;
		}
		
		while (counter < ship_blocks && coordinate.y >= 0 && coordinate.y <= 9)
		{
			
			if (board[coordinate.x][coordinate.y] > 1)
			{
				return true;
			}
			else if (coordinate.x > 0 && (board[coordinate.x - 1][coordinate.y] > 1))
			{
				return true;
			}
			else if (coordinate.x < 9 && (board[coordinate.x + 1][coordinate.y] > 1))
			{
				return true;
			}
			counter++;
			coordinate.y++;
		}
	}
	else
	{
		if (coordinate.x > 0)
		{
			ship_blocks++;
			coordinate.x--;
		}
		
		while (counter < ship_blocks && coordinate.x >= 0 && coordinate.x <= 9)
		{
			if (board[coordinate.x][coordinate.y] > 1)
			{
				return true;
			}
			else if (coordinate.y > 0 && (board[coordinate.x][coordinate.y - 1] > 1))
			{
				return true;
			}
			else if (coordinate.y < 9 && (board[coordinate.x][coordinate.y + 1] > 1))
			{
				return true;
			}
			counter++;
			coordinate.x++;
		}
	}

	return false;
}