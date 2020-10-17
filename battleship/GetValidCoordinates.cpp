#include <iostream>
#include "Player.h"


void GetValidCoordinates(Board defender_board, Coordinate & attacker_move)
{
	while (true)
	{
		GetCoordinates(attacker_move);
		if (CheckCoordinates(defender_board.board, attacker_move))
		{
			return;
		}
		else
		{
			std::cout << "\nTry Again!\n";
		}
	}
}

