#include <iostream>
#include "Player.h"
#include "Declarations.h"
#include "Settings.h"

void Game(Settings gs)
{
	Player* player1 = CreatePlayer();

	player1->_board.NewBoard();

	player1->_board.BoardConf(false);


	Player* player2;
	if (gs.gameMode)
	{
		player2 = AISettings();
	}
	else
	{
		system("CLS");
		player2 = CreatePlayer();

		player2->_board.NewBoard();

		player2->_board.BoardConf(false);
	}


	while(1)
	{
		Wait();
		Start(player1, player2, gs);
		if (GameOverScreen(gs.inputDevices))
		{
			ResetPlayersData(player1, player2, gs.gameMode);
			continue;
		}
		else
		{
			DeletePlayersData(player1, player2);
			return;
		}
	}
}