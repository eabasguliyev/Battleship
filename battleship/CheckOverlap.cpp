#include <iostream>

bool CheckOverlap(int ** board, char orientation, int x, int y, int ship_blocks)
{
	ship_blocks += 2;

	int counter = 0;

	if (orientation == 'h')
	{
		if (y > 0)
			y--;
		
		while (counter < ship_blocks && y >= 0 && y <= 9)
		{
			
			if (board[x][y] > 1)
			{
				return true;
			}
			else if (x > 0 && (board[x - 1][y] > 1))
			{
				return true;
			}
			else if (x < 9 && (board[x + 1][y] > 1))
			{
				return true;
			}
			counter++;
			y++;
		}
	}
	else
	{
		if (x > 0)
			x--;
		while (counter < ship_blocks && x >= 0 && x <= 9)
		{
			if (board[x][y] > 1)
			{
				return true;
			}
			else if (y > 0 && (board[x][y - 1] > 1))
			{
				return true;
			}
			else if (y < 9 && (board[x][y + 1] > 1))
			{
				return true;
			}
			counter++;
			x++;
		}
	}

	return false;
}