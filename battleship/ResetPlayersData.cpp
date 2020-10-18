#include "Player.h"

void ResetPlayersData(Player * player1, Player * player2, bool is_computer, bool inputDevices)
{
	player1->_board.ResetBoard();
	player1->_board.ResetBlocks();
	player2->_board.ResetBoard();
	player2->_board.ResetBlocks();

	player1->_board.BoardConf(player1->_board, inputDevices);

	if (is_computer)
	{
		ClearStates();
		ResetAIData(true);
		player2->_board.BoardConfAI();
	}
	else
	{
		player2->_board.BoardConf(player2->_board, inputDevices);
	}
}