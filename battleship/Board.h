#pragma once
#include "Declarations.h"
#include <time.h>

struct Board
{
	int** board;
	int ship_blocks = 17;

	int board_size = 10;

	void PrintBoard(COORD coordinate)
	{
		HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleCursorPosition(hConsoleOUT, coordinate);

		std::cout << "   0  1  2  3  4  5  6  7  8  9\n";

		for (size_t i = 0; i < board_size; i++)
		{
			coordinate.Y++;
			SetConsoleCursorPosition(hConsoleOUT, coordinate);
			std::cout << i << ' ';
			SetConsoleTextAttribute(hConsoleOUT, GREEN);
			for (size_t j = 0; j < board_size; j++)
			{
				switch (board[i][j])
				{
				case MISSED:
					std::cout << " * ";
					break;
				case SPACE:
					std::cout << " . ";
					break;
				case HIT:
					std::cout << " X ";
					break;
				case DESTROYER:
					std::cout << " D ";
					break;
				case SUBMARINE:
					std::cout << " S ";
					break;
				case CRUISER:
					std::cout << " C ";
					break;
				case BATTLESHIP:
					std::cout << " B ";
					break;
				case CARRIER:
					std::cout << " A ";
					break;
				default:
					break;
				}
			}
			std::cout << std::endl;
			SetConsoleTextAttribute(hConsoleOUT, WHITE);
		}
	}
	
	void PrintOpponentBoard(COORD coordinate)
	{
		HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleCursorPosition(hConsoleOUT, coordinate);

		std::cout << "   0  1  2  3  4  5  6  7  8  9\n";
		for (size_t i = 0; i < board_size; i++)
		{
			coordinate.Y++;
			SetConsoleCursorPosition(hConsoleOUT, coordinate);
			std::cout << i << ' ';
			SetConsoleTextAttribute(hConsoleOUT, RED);
			for (size_t j = 0; j < board_size; j++)
			{
				switch (board[i][j])
				{
				case MISSED:
					std::cout << " * ";
					break;
				case HIT:
					std::cout << " X ";
					break;
				default:
					std::cout << " . ";
					break;
				}
			}
			std::cout << std::endl;
			SetConsoleTextAttribute(hConsoleOUT, WHITE);
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

	void BoardConf(bool is_computer)
	{
		if (is_computer)
		{
			PlaceAIShips(board, 5, CARRIER);
			PlaceAIShips(board, 4, BATTLESHIP);
			PlaceAIShips(board, 3, CRUISER);
			PlaceAIShips(board, 3, SUBMARINE);
			PlaceAIShips(board, 2, DESTROYER);
		}
		else
		{
			system("CLS");
			PrintBoard({ 42, 8 });
			PlaceTheShip(board, 5, CARRIER);
			system("CLS");
			PrintBoard({ 42, 8 });
			PlaceTheShip(board, 4, BATTLESHIP);
			system("CLS");
			PrintBoard({ 42, 8 });
			PlaceTheShip(board, 3, CRUISER);
			system("CLS");
			PrintBoard({ 42, 8 });
			PlaceTheShip(board, 3, SUBMARINE);
			system("CLS");
			PrintBoard({ 42, 8 });
			PlaceTheShip(board, 2, DESTROYER);
		}
	}
	
	void ResetBlocks()
	{
		ship_blocks = 17;
	}
};