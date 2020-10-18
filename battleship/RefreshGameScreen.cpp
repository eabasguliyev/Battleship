#include <iostream>
#include "Player.h"

void PrintBoards(Player* defender, Player* attacker, bool gameMode)
{
	system("CLS");
	COORD coordinate{ 22,6 };

	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	if (gameMode)
		std::cout << defender->name << " turn!\n\n";
	else
		std::cout << attacker->name << " turn!\n\n";

	SetConsoleCursorPosition(hConsoleOUT, { 45, 0 });
	PrintScores(defender, attacker);
	SetConsoleCursorPosition(hConsoleOUT, coordinate);

	defender->_board.PrintOpponentBoard({ 21, 8 });
	attacker->_board.PrintBoard({ 60, 8 });
}


void PrintScores(Player* player1, Player* player2)
{
	std::cout << player1->name << ' ' << player1->score << " : " << player2->score << ' ' << player2->name << '\n';
}

void PrintWinner(Player* player)
{
	std::cout << "Winner is " << player->name << "!\n";
}