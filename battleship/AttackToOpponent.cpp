#include <iostream>
#include "Player.h"

bool CheckCoordinates(int ** board, Coordinate _coordinate, bool ai, bool sides, bool orientation, bool direction)
{
	if (_coordinate.x < 0 || _coordinate.x > 9 || _coordinate.y < 0 || _coordinate.y > 9)
	{
		return false;
	}
	else if (board[_coordinate.x][_coordinate.y] == -1 || board[_coordinate.x][_coordinate.y] == 1)
	{
		return false;
	}
	else if(ai)
	{
		int i = 0;
		int j = 0;
		int size1 = 0;
		int size2 = 0;

		if (sides)
		{
			if (orientation)
			{
				i = (_coordinate.x == 0) ? _coordinate.x : _coordinate.x - 1;
				size1 = (_coordinate.x == 9) ? _coordinate.x : _coordinate.x + 1;

				if (direction)
				{
					if (_coordinate.y == 0)
					{
						return true;
					}
					else
					{
						j = _coordinate.y + 1;
					}
				}
				else
				{
					if (_coordinate.y == 9)
					{
						return true;
					}
					else
					{
						j = _coordinate.y - 1;
					}
				}
				size2 = j;
			}
			else
			{
				j = (_coordinate.y == 0) ? _coordinate.y : _coordinate.y - 1;
				size2 = (_coordinate.y == 9) ? _coordinate.y : _coordinate.y + 1;

				if (direction)
				{
					if (_coordinate.x == 9)
					{
						return true;
					}
					else
					{
						i = _coordinate.x + 1;
					}
				}
				else
				{
					if (_coordinate.x == 0)
					{
						return true;
					}
					else
					{
						i = _coordinate.x - 1;
					}
				}
				size1 = i;
			}
		}
		else
		{
			i = (_coordinate.x == 0) ? _coordinate.x : _coordinate.x - 1;
			j = (_coordinate.y == 0) ? _coordinate.y : _coordinate.y - 1;
			size1 = (_coordinate.x == 9) ? _coordinate.x : _coordinate.x + 1;
			size2 = (_coordinate.y == 9) ? _coordinate.y : _coordinate.y + 1;
		}

		int temp_j = j;
		while (i <= size1)
		{
			while (j <= size2)
			{
				if (board[i][j] == 1)
				{
					return false;
				}
				j++;
			}
			j = temp_j;
			i++;
		}
	}
	return true;
}

bool AttackToOpponent(Player *& defender, Player *& attacker)
{
	if (defender->_board.board[attacker->_coordinate.x][attacker->_coordinate.y] > 1)
	{
		defender->_board.board[attacker->_coordinate.x][attacker->_coordinate.y] = 1;
		defender->_board.ship_blocks--;
		return true;
	}
	else
	{
		defender->_board.board[attacker->_coordinate.x][attacker->_coordinate.y] = -1;
		return false;
	}
}