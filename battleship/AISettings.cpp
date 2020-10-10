#include <iostream>
#include "Player.h"
#include "Board.h"


Player* AISettings()
{
	Player* computer = new Player;

	computer->name = _strdup("Computer");
	computer->_board.NewBoard();
	computer->_board.BoardConf(true);
	return computer;
}