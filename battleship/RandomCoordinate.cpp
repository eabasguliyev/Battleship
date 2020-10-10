#include "Player.h"
#include <time.h>

Coordinate RandomCoordinate(Board board)
{
	Coordinate coordinate;
	srand(time(NULL));
	while (true)
	{
		coordinate.x = rand() % 10;
		coordinate.y = rand() % 10;
		if (CheckCoordinates(board, coordinate))
		{
			return coordinate;
		}
	}
}