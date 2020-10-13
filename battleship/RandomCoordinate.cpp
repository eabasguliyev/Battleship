#include "Player.h"
#include <time.h>

Coordinate RandomCoordinate(Board board)
{
	Coordinate coordinate;
	while (true)
	{
		coordinate.x = rand() % 10;
		coordinate.y = rand() % 10;
		if (CheckCoordinates(board.board, coordinate, true))
		{
			return coordinate;
		}
	}
}