#include <iostream>
#include "Player.h"
#include "Declarations.h"
#include <Windows.h>
#include <time.h>
#include "Settings.h"

void Start(Player * player1, Player * player2, Settings gs)
{
	int turn = Draw();

	while (true)
	{
		if (turn)
		{
			if (gs.gameMode)
			{
				PrintBoards(player2, player1, gs.gameMode);
				Sleep(1000); 
				short status = AI(player1, player2, gs.diff, gs.sound);
				if (status)
				{
					PrintBoards(player2, player1, gs.gameMode);
					PrintWinner(player2);
					PrintScores(player1, player2);
					break;
				}
			}
			else
			{
				PrintBoards(player1, player2);
				GetValidCoordinates(player1->_board, player2->_coordinate);
				if (AttackToOpponent(player1, player2))
				{
					if (gs.sound)
					{
						SoundEffects(1);
						Sleep(1000);
					}

					if (player1->_board.CheckBlocks())
					{
						PrintWinner(player2);
						PrintScores(player1, player2);
						break;
					}

					continue;
				}
			}
		}
		else
		{
			PrintBoards(player2, player1);
			
			GetValidCoordinates(player2->_board, player1->_coordinate);

			if (AttackToOpponent(player2, player1))
			{
				if (gs.sound)
				{
					SoundEffects(1);
					Sleep(1000);
				}
				if (player2->_board.CheckBlocks())
				{
					PrintWinner(player1);
					PrintScores(player1, player2);
					break;
				}
				continue;
			}
		}
		turn = (turn) ? false : true;
		PrintBoards(player2, player1);
		if (gs.sound)
		{
			SoundEffects(0);
			Sleep(500);
		}
	}

	Wait();
}