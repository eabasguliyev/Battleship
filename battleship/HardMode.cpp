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

// 0 means AI_WIN true
// 1 means one more attack, state 2.
// 2 means next turn, coo is opposite direction
// 3 means try again, coo is oppsoite direction

//state 2
// 0 ai win true
// 1 one more attack
// 2 next turn, state 3 opposite
// 3 try again, state 3 opposite


int GetStatusCode(Player* human, Player* computer, Coordinate& last_coo, bool & AI_WIN)
{
	if (CheckCoordinates(human->_board, last_coo))
	{
		CopyCoordinate(computer->_coordinate, last_coo);

		if (AttackToOpponent(human, computer))
		{
			if (AIChecker(human->_board, AI_WIN))
				return 0;

			CopyCoordinate(last_coo, computer->_coordinate);
			return 1;
		}
		return 2;
	}
	return 3;
}
int VerticalAttack(Player* human, Player* computer, bool direction, Coordinate & last_coo, bool & AI_WIN)
{
	if (direction)
		last_coo.x++;
	else
		last_coo.x--;

	return GetStatusCode(human, computer, last_coo, AI_WIN);
}

int HorizontalAttack(Player* human, Player* computer, bool direction, Coordinate& last_coo, bool & AI_WIN)
{
	if (direction)
		last_coo.y++;
	else
		last_coo.y--;

	return GetStatusCode(human, computer, last_coo, AI_WIN);
}
void ResetData(int & STATE, Coordinate & last_coo, short & tries, int & hits, bool & orientation, bool & direction)
{
	STATE = 0;
	last_coo.x = 0;
	last_coo.y = 0;
	tries = 0;
	hits = 0;
	orientation = false;
	direction = false;
}

void HardMode(Player* human, Player* computer, bool &AI_WIN)
{
	static int STATE = 0;
	static Coordinate last_move;
	static int hits = 0;

	Coordinate temp_coordinate;

	static bool orientation = 0;
	static bool direction = 0;

	static short tries = 0;
	do
	{
		if(STATE == 0)
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
				continue;
			}
			ResetData(STATE, last_move, tries, hits, orientation, direction);
			return;
		}
		else
		{
			do
			{
				if (STATE != 3)
					CopyCoordinate(temp_coordinate, last_move);

				if (hits == 5)
				{
					ResetData(STATE, last_move, tries, hits, orientation, direction);
					break;
				}

				short status;
				if (orientation)
				{
					status = HorizontalAttack(human, computer, direction, temp_coordinate, AI_WIN);
				}
				else
				{
					status = VerticalAttack(human, computer, direction, temp_coordinate, AI_WIN);
				}

				if (status == 0)
					return;
				else if (status == 1)
				{
					CopyCoordinate(last_move, temp_coordinate);
					(STATE == 1) ? STATE++ : false;
					hits++;
					continue;
				}
				else
				{
					if (STATE == 1)
					{
						if (direction)
						{
							direction = false;
							orientation = true;
						}
						else
						{
							direction = true;
						}

						tries++;

						if (tries == 4)
						{
							STATE = 0;
							direction = false;
							orientation = false;
							return;
						}

						if (status == 2)
							return;
						continue;
					}
					else if (STATE == 2)
					{
						if (orientation)
						{
							temp_coordinate.y = (direction) ? (temp_coordinate.y - hits) : (temp_coordinate.y + hits);
						}
						else
						{
							temp_coordinate.x = (direction) ? (temp_coordinate.x - hits) : (temp_coordinate.x + hits);
						}
						if (CheckCoordinates(human->_board, temp_coordinate))
						{
							STATE++;
							break;
						}
						ResetData(STATE, last_move, tries, hits, orientation, direction);
						return;
					}
					else
					{
						if (status == 2)
						{
							ResetData(STATE, last_move, tries, hits, orientation, direction);
							return;
						}
						if (status == 3)
							continue;
					}
				}
			} while (true);

			if (STATE == 3)
			{
				direction = (direction) ? false : true;
				continue;
			}
		}
	}while (1);
}