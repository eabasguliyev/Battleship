#include <iostream>
#include "Player.h"
#include "Declarations.h"
#include <Windows.h>
#include <time.h>


int Start(Player * player1, Player * player2, int difficulty)
{
	int turn = Draw();
	
	while (true)
	{
		if (turn)
		{
			if (player2->is_computer)
			{
				bool AI_WIN = false;

				switch (difficulty)
				{
				case Easy:
				{
					EasyMode(player1, player2, AI_WIN);
				}
				break;
				case Normal:
				{
					HardMode(player1, player2, AI_WIN);
				}
					break;
				case Legend:
				{
					continue;
				}
				break;
				default:
					break;
				}

				if (AI_WIN)
				{
					AI_WIN = false;
					PrintBoards(player2, player1);
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
	}

	std::cin.ignore(255, '\n');
	std::cout << "Press enter to continue";
	std::cin.get();

	return 0;
}