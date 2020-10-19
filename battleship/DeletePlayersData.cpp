#include "Player.h"

void DeletePlayersData(Player*& player1, Player*& player2, bool is_computer)
{
	player1->_board.ResetBoard();
	player1->_board.ResetBlocks();
	player2->_board.ResetBoard();
	player2->_board.ResetBlocks();
	delete[] player1->name;
	player1->_board.DeleteBoard();
	delete player1;

	delete[] player2->name;
	player2->_board.DeleteBoard();
	delete player2;

	if (is_computer)
	{
		ClearStates();
		ResetAIData(true);
	}
}