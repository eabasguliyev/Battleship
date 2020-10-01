#include <iostream>
#include "Player.h"
#include <time.h>
#include "Declarations.h";

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

void EasyMode(Player * human, Player * computer, bool& AI_WIN)
{
	while (true)
	{
		computer->_coordinate = RandomCoordinate(human->_board);
		if (AttackToOpponent(human, computer))
		{
			if (human->_board.CheckBlocks())
			{
				AI_WIN = true;
				return;
			}
			continue;
		}
		return;
	}
}