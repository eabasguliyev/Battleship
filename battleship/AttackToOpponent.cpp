#include <iostream>
#include "Player.h"

bool CheckCoordinates(Board& _board, Coordinate& _coordinate)
{
	if (_coordinate.x < 0 || _coordinate.x > 9 || _coordinate.y < 0 || _coordinate.y > 9)
	{
		return false;
	}
	else if (_board.board[_coordinate.x][_coordinate.y] == -1 || _board.board[_coordinate.x][_coordinate.y] == 1)
	{
		return false;
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