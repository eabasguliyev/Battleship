#include "Player.h"
#include "Declarations.h"
#define MAX_HIT 5;

bool AIChecker(Board board, bool & AI_WIN)
{
	if (board.CheckBlocks())
	{
		AI_WIN = true;
		return true;
	}
	return false;
}

void CopyCoordinate(Coordinate& coo1, Coordinate& coo2)
{
	coo1.x = coo2.x;
	coo1.y = coo2.y;
}
void HardMode(Player* human, Player* computer, bool &AI_WIN)
{
	static int STATE = 0;
	static Coordinate last_move;
	static int hits = 0;

	Coordinate temp_coordinate;

	static bool orientation = 0;
	static bool direction = 0;

	
	do
	{
		if (STATE == 0)
		{
			// random x y
			computer->_coordinate = RandomCoordinate(human->_board);

			
			if (AttackToOpponent(human, computer))
			{
				if (AIChecker(human->_board, AI_WIN))
					return;

				CopyCoordinate(last_move, computer->_coordinate);
				STATE++;
				hits++;
			}
			else
				return;
		}
		
		if (STATE == 1)
		{
			// kenarlari yoxla
			CopyCoordinate(temp_coordinate, last_move);

			
			if (orientation == 0) //vertical
			{
				if (direction == 0)
				{
					temp_coordinate.x--;
					if (CheckCoordinates(human->_board, temp_coordinate))
					{
						CopyCoordinate(computer->_coordinate, temp_coordinate);

						
						if (AttackToOpponent(human, computer))
						{
							if (AIChecker(human->_board, AI_WIN))
								return;

							CopyCoordinate(last_move, computer->_coordinate);
							STATE++;
							hits++;
						}
						else
						{
							direction = 1;
							return;
						}
					}
					else
					{
						direction = 1;
						continue;
					}
				}
				else
				{
					temp_coordinate.x++;
					if (CheckCoordinates(human->_board, temp_coordinate))
					{
						CopyCoordinate(computer->_coordinate, temp_coordinate);


						if (AttackToOpponent(human, computer))
						{
							if (AIChecker(human->_board, AI_WIN))
								return;
							CopyCoordinate(last_move, computer->_coordinate);
							STATE++;
							hits++;
						}
						else
						{
							direction = 0;
							orientation = 1;
							return;
						}
					}
					else
					{
						direction = 0;
						orientation = 1;
						continue;
					}
				}
			}
			else
			{
				if (direction == 0)
				{
					temp_coordinate.y--;
					if (CheckCoordinates(human->_board, temp_coordinate))
					{
						CopyCoordinate(computer->_coordinate, temp_coordinate);


						if (AttackToOpponent(human, computer))
						{
							if (AIChecker(human->_board, AI_WIN))
								return;
							CopyCoordinate(last_move, computer->_coordinate);
							STATE++;
						}
						else
						{
							direction = 1;
							return;
						}
					}
					else
					{
						direction = 1;
						continue;
					}
				}
				else
				{
					temp_coordinate.y++;
					if (CheckCoordinates(human->_board, temp_coordinate))
					{
						CopyCoordinate(computer->_coordinate, temp_coordinate);


						if (AttackToOpponent(human, computer))
						{
							if (AIChecker(human->_board, AI_WIN))
								return;
							CopyCoordinate(last_move, computer->_coordinate);
							STATE++;
							hits++;
						}
						else
						{
							direction = 0;
							orientation = 0;
							STATE = 0;
							return;
						}
					}
					else
					{
						direction = 0;
						orientation = 0;
						STATE = 0;
						continue;
					}
				}
			}

		}
		
		if (STATE == 2)
		{
			// tapilan istiqametde davam et

			CopyCoordinate(temp_coordinate, last_move);

			if (orientation == 0)
			{
				if (direction == 0)
				{
					do
					{
						temp_coordinate.x--;
						if (CheckCoordinates(human->_board, temp_coordinate))
						{
							CopyCoordinate(computer->_coordinate, temp_coordinate);
							if (AttackToOpponent(human, computer))
							{
								if (AIChecker(human->_board, AI_WIN))
									return;
								continue;
							}
							STATE = 3;
							hits++;
							return;
						}
						else
						{
							return;
						}
					} while (1);
				}
				else
				{
					do
					{
						temp_coordinate.x++;
						if (CheckCoordinates(human->_board, temp_coordinate))
						{
							CopyCoordinate(computer->_coordinate, temp_coordinate);
							if (AttackToOpponent(human, computer))
							{
								if (AIChecker(human->_board, AI_WIN))
									return;
								continue;
							}
							STATE = 3;
							hits++;
							return;
						}
						else
						{
							break;
						}
					} while (1);
				}
			}
			else
			{
				if (direction == 0)
				{
					do
					{
						temp_coordinate.y--;
						if (CheckCoordinates(human->_board, temp_coordinate))
						{
							CopyCoordinate(computer->_coordinate, temp_coordinate);
							if (AttackToOpponent(human, computer))
							{
								if (AIChecker(human->_board, AI_WIN))
									return;
								continue;
							}
							STATE = 3;
							hits++;
							return;
						}
						else
						{
							break;
						}
					} while (1);
				}
				else
				{
					do
					{
						temp_coordinate.y++;
						if (CheckCoordinates(human->_board, temp_coordinate))
						{
							CopyCoordinate(computer->_coordinate, temp_coordinate);
							if (AttackToOpponent(human, computer))
							{
								if (AIChecker(human->_board, AI_WIN))
									return;
								continue;
							}
							STATE = 3;
							hits++;
							return;
						}
						else
						{
							break;
						}
					} while (1);
				}
			}

			STATE = 3;
		}
		else if (STATE == 3)
		{
			// arxani yoxla

			CopyCoordinate(temp_coordinate, last_move);
			if (orientation == 0)
			{
				if (direction == 0)
				{
					do
					{
						temp_coordinate.x++;
						if (CheckCoordinates(human->_board, temp_coordinate))
						{
							CopyCoordinate(computer->_coordinate, temp_coordinate);

							if (human->_board.board[computer->_coordinate.x][computer->_coordinate.y] != -1)
							{
								if (!AttackToOpponent(human, computer))
								{
									break;
								}
								hits++;
							}
						}
						else
						{
							break;
						}
					} while (1);
				}
				else
				{
					do
					{
						temp_coordinate.x--;
						if (CheckCoordinates(human->_board, temp_coordinate))
						{
							CopyCoordinate(computer->_coordinate, temp_coordinate);

							if (human->_board.board[computer->_coordinate.x][computer->_coordinate.y] != -1)
							{
								if (!AttackToOpponent(human, computer))
								{
									break;
								}
								hits++;
							}
						}
						else
						{
							break;
						}
					} while (1);
				}
			}
			else
			{
				if (direction == 0)
				{
					do
					{
						temp_coordinate.y++;
						if (temp_coordinate.y > 0 && temp_coordinate.y < 10)
						{
							CopyCoordinate(computer->_coordinate, temp_coordinate);

							if (human->_board.board[computer->_coordinate.x][computer->_coordinate.y] != -1)
							{
								if (!AttackToOpponent(human, computer))
								{
									break;
								}
								hits++;
							}
						}
						else
						{
							break;
						}
					} while (1);
				}
				else
				{
					do
					{
						temp_coordinate.y--;
						if (CheckCoordinates(human->_board, temp_coordinate))
						{
							CopyCoordinate(computer->_coordinate, temp_coordinate);

							if (human->_board.board[computer->_coordinate.x][computer->_coordinate.y] != -1)
							{
								if (!AttackToOpponent(human, computer))
								{
									break;
								}
								hits++;
							}
						}
						else
						{
							break;
						}
					} while (1);
				}
			}

			STATE = 0;
		}
	}while (1);
	
	return;
}