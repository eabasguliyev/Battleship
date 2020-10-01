#include <iostream>
#include "Player.h"


void PrintWinner(Player* player)
{
	std::cout << "Winner is " << player->name << "!\n";
	player->score++;
}