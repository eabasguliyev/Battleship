#include <iostream>
#include "Player.h"

void PrintBoards(Player* defender, Player* attacker)
{
	system("CLS");
	std::cout << defender->name << "'s board\n\n";
	defender->_board.PrintOpponentBoard();
	std::cout << attacker->name << "'s board\n\n";
	attacker->_board.PrintBoard();
}