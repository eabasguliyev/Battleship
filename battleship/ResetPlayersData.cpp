#include "Player.h"

void ResetPlayersData(Player * player1, Player * player2, bool is_computer)
{
	player1->_board.ResetBoard();
	player1->_board.ResetBlocks();
	player2->_board.ResetBoard();
	player2->_board.ResetBlocks();

	player1->_board.BoardConf(false);

	if (is_computer)
	{
		ClearStates();
		ResetAIData(true);
		player2->_board.BoardConf(true);
	}
	else
	{
		player2->_board.BoardConf(false);
	}
}