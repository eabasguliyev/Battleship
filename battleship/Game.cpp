#include <iostream>
#include "Player.h"
#include "Declarations.h"
#include "Settings.h"

void Game(Settings gs)
{
	Player* player1 = CreatePlayer();

	player1->_board.NewBoard();

	player1->_board.BoardConf(player1->_board, gs.inputDevices);


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

		player2->_board.BoardConf(player2->_board, gs.inputDevices);
	}


	while(1)
	{
		if (gs.inputDevices)
		{
			Sleep(2000);
		}
		else
		{
			Wait();
		}
		

		Start(player1, player2, gs);
		if (GameOverScreen(gs.inputDevices))
		{
			ResetPlayersData(player1, player2, gs.gameMode, gs.inputDevices);
			continue;
		}
		else
		{

			DeletePlayersData(player1, player2, gs.gameMode);
			return;
		}
	}
}