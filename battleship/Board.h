#pragma once
#include "Declarations.h"


struct Board
{
	int** board;
	int ship_blocks = 17;

	int board_size = 10;


	void PrintBoard()
	{
		std::cout << "   0  1  2  3  4  5  6  7  8  9\n";
		for (size_t i = 0; i < board_size; i++)
		{
			std::cout << i << ' ';
			for (size_t j = 0; j < board_size; j++)
			{
				if (board[i][j] == 0)
				{
					std::cout << " . ";
				}
				else if (board[i][j] == -1)
				{
					std::cout << " * ";
				}
				else if (board[i][j] == 1)
				{
					std::cout << " X ";
				}
				else if (board[i][j] == CARRIER)
				{
					std::cout << " A ";
				}
				else if (board[i][j] == BATTLESHIP)
				{
					std::cout << " B ";
				}
				else if (board[i][j] == CRUISER)
				{
					std::cout << " C ";
				}
				else if (board[i][j] == SUBMARINE)
				{
					std::cout << " S ";
				}
				else if (board[i][j] == DESTROYER)
				{
					std::cout << " D ";
				}
			}
			std::cout << std::endl;
		}
	}
	
	void PrintOpponentBoard()
	{
		std::cout << "   0  1  2  3  4  5  6  7  8  9\n";
		for (size_t i = 0; i < board_size; i++)
		{
			std::cout << i << ' ';
			for (size_t j = 0; j < board_size; j++)
			{
				if (board[i][j] == -1)
				{
					std::cout << " * ";
				}
				else if (board[i][j] == 1)
				{
					std::cout << " X ";
				}
				else
				{
					std::cout << " . ";
				}
			}
			std::cout << std::endl;
		}
	}
	
	void ResetBoard()
	{
		for (size_t i = 0; i < board_size; i++)
		{
			for (size_t j = 0; j < board_size; j++)
			{
				board[i][j] = 0;
			}
		}
	}

	void NewBoard()
	{
		board = new int* [board_size];

		for (size_t i = 0; i < board_size; i++)
		{
			board[i] = new int[board_size] {};
		}
	}

	bool CheckBlocks()
	{
		if (ship_blocks == 0)
			return true;
		return false;
	}

	void BoardConf()
	{
		system("CLS");
		PrintBoard();
		std::cout << "Add Carrier\n";
		PlaceTheShip(board, 5, CARRIER);
		system("CLS");
		PrintBoard();

		std::cout << "Add Battleship\n";
		PlaceTheShip(board, 4, BATTLESHIP);
		system("CLS");
		PrintBoard();

		std::cout << "Add Cruiser\n";
		PlaceTheShip(board, 3, CRUISER);
		system("CLS");
		PrintBoard();

		std::cout << "Add Submarine\n";
		PlaceTheShip(board, 3, SUBMARINE);
		system("CLS");
		PrintBoard();

		std::cout << "Add Destroyer\n";
		PlaceTheShip(board, 2, DESTROYER);
	}

	void BoardConfAI()
	{
		PlaceAIShips(board, 5, CARRIER);
		PlaceAIShips(board, 4, BATTLESHIP);
		PlaceAIShips(board, 3, CRUISER);
		PlaceAIShips(board, 3, SUBMARINE);
		PlaceAIShips(board, 2, DESTROYER);
	}
	
	void ResetBlocks()
	{
		ship_blocks = 17;
	}
};