#include <iostream>
#include "Player.h"
#include "Declarations.h"


void Game(short difficulty)
{
	Player* player1 = CreatePlayer();

	player1->_board.NewBoard();

	player1->_board.BoardConf();


	Player* player2;
	if (difficulty)
	{
		player2 = AISettings();
	}
	else
	{
		system("CLS");
		player2 = CreatePlayer();

		player2->_board.NewBoard();

		player2->_board.BoardConf();
	}


	while(true)
	{
		std::cout << "Press enter to start game!";
		std::cin.ignore(255, '\n');
		std::cin.get();
		Start(player1, player2, difficulty);

		if (GameOverScreen())
		{
			ResetPlayersData(player1, player2);
		}
		else
		{
			DeletePlayersData(player1, player2);
			return;
		}
	}
}