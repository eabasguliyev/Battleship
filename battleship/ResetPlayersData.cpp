#include "Player.h"

void ResetPlayersData(Player * player1, Player * player2)
{
	player1->_board.ResetBoard();
	player1->_board.ResetBlocks();
	player2->_board.ResetBoard();
	player2->_board.ResetBlocks();

	player1->_board.BoardConf();

	if (player2->is_computer)
	{
		player2->_board.BoardConfAI();
	}
	else
	{
		player2->_board.BoardConf();
	}
}