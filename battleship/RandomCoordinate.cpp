#include "Player.h"
#include <time.h>

void RandomCoordinate(int** board, Coordinate & coordinate)
{
	Coordinate temp;
	while (true)
	{
		temp.x = rand() % 10;
		temp.y = rand() % 10;
		if (CheckCoordinates(board, temp, true))
		{
			coordinate.x = temp.x;
			coordinate.y = temp.y;
			return;
		}
	}
}