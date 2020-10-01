#pragma once
#include <iostream>
#include "Board.h"

struct Coordinate
{
	int x, y;
};

struct Player
{
	char* name;
	bool is_computer = false;

	int score = 0;


	Board _board;
	Coordinate _coordinate;

	void ResetScore()
	{
		score = 0;
	}
};