#include "Player.h"

void DeletePlayersData(Player*& player1, Player*& player2)
{
	delete[] player1->name;
	delete[] player1->_board.board;
	delete player1;

	delete[] player2->name;
	delete[] player2->_board.board;
	delete player2;
}