#include <iostream>
#include "Player.h"


Player* CreatePlayer()
{
	Player* player = new Player;

	if (player)
	{
		std::cout << "Enter player name: ";

		char* buf = InputName();
		
		player->name = _strdup(buf);
		delete[] buf;

		//std::cout << "Player created!" << std::endl;

		return player;
	}
	exit(1);
}