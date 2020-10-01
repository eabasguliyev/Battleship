#include <iostream>
#include "Player.h"


void PrintScores(Player* player1, Player * player2)
{
	std::cout << player1->name << ' ' << player1->score << " : " << player2->score << ' ' << player2->name << '\n';
}