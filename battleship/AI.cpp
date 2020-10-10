#include <time.h>
#include "Player.h"
#include "Declarations.h"
#include "Settings.h"

#define MAX_TRY 4

static int MAX_HIT = 5;
static int STATE = 0;
static Coordinate last_move;
static int hits = 0;
static Coordinate temp_coordinate;
static char direction_states = 0;
static bool orientation = 0;
static bool direction = 0;
static short tries = 0;

enum STATUS_CODE {
	AIWIN, ONE_MORE_ATTACK, NEXT_TURN_OPPOSITE_DIRECTION, TRY_AGAIN_OPPOSITE_DIRECTION
};

enum STATE_CODE
{
	FIRST_ATACK, TRYSIDES, ATTACK_AGAIN, TRY_BACK
};

enum DIRECTIONS
{
	UP = 1, DOWN, LEFT, RIGHT
};
bool AIChecker(Board board)
{
	if (board.CheckBlocks())
	{
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


int GetStatusCode(Player* human, Player* computer, Coordinate& last_coo)
{
	if (CheckCoordinates(human->_board, last_coo))
	{
		CopyCoordinate(computer->_coordinate, last_coo);

		if (AttackToOpponent(human, computer))
		{
			if (AIChecker(human->_board))
				return 0;

			CopyCoordinate(last_coo, computer->_coordinate);
			return 1;
		}
		return 2;
	}
	return 3;
}
int VerticalAttack(Player* human, Player* computer, bool direction, Coordinate& last_coo)
{
	if (direction)
		last_coo.x++;
	else
		last_coo.x--;

	if (last_coo.x < 0 || last_coo.x > 9)
		return 3;

	return GetStatusCode(human, computer, last_coo);
}

int HorizontalAttack(Player* human, Player* computer, bool direction, Coordinate& last_coo)
{
	if (direction)
		last_coo.y++;
	else
		last_coo.y--;

	if (last_coo.y < 0 || last_coo.y > 9)
		return 3;

	return GetStatusCode(human, computer, last_coo);
}
void ResetAIData()
{
	STATE = 0;
	tries = 0;
	hits = 0;
	orientation = false;
	direction = false;
}

bool CheckState(int state, char& direction_states);

bool RemainingDirections(char direction_states)
{
	for (size_t i = 1; i < 5; i++)
	{
		if (!CheckState(i, direction_states))
			return true;
	}
	return false;
}

void ClearStates()
{
	direction_states >>= 8;
}

void SetState(int state, char& direction_states)
{
	switch (state)
	{
	case 1:
		direction_states |= 1;
		break;
	case 2:
		direction_states |= 2;
		break;
	case 3:
		direction_states |= 4;
		break;
	case 4:
		direction_states |= 8;
		break;
	}
}

bool CheckState(int state, char& direction_states)
{
	switch (state)
	{
	case 1:
		return direction_states & 1;
	case 2:
		return direction_states & 2;
	case 3:
		return direction_states & 4;
	case 4:
		return  direction_states & 8;
	default:
		return false;
	}
}
bool SetDirections(bool& orientation, bool& direction, char& direction_states)
{
	srand(time(NULL));

	while (true)
	{

		if (!RemainingDirections(direction_states))
		{
			ClearStates();
			return false;
		}

		short state = rand() % 4 + 1;

		short status = CheckState(state, direction_states);

		if (status == 2)
		{
			return false;
		}
		else if (status == 1)
		{
			continue;
		}

		if (state == UP || state == DOWN)
			orientation = false;
		else
			orientation = true;

		if (state == UP || state == LEFT)
			direction = false;
		else
			direction = true;

		SetState(state, direction_states);
		return true;
	}
}

void GoBack(bool orientation, bool direction, short offset, Coordinate& coo)
{
	if (orientation)
	{
		coo.y = (direction) ? (coo.y - offset) : (coo.y + offset);
	}
	else
	{
		coo.x = (direction) ? (coo.x - offset) : (coo.x + offset);
	}
}


bool  AI(Player* human, Player* computer, short diff, bool sound)
{
	while (1)
	{
		if (STATE == FIRST_ATACK)
		{
			// random x y
			computer->_coordinate = RandomCoordinate(human->_board);


			if (AttackToOpponent(human, computer))
			{
				if (AIChecker(human->_board))
					return true;

				if (diff != VeryEasy)
				{
					CopyCoordinate(last_move, computer->_coordinate);
					STATE++;
					hits++;
				}
				if (sound)
				{
					SoundEffects(1);
					Sleep(500);
				}
				/*std::cout << "Hit: " << computer->_coordinate.x << ' ' << computer->_coordinate.y;
				
				std::cin.ignore(255, '\n');
				std::cin.get();*/
				
				continue;
			}
			/*std::cout << "Missed: " << computer->_coordinate.x << ' ' << computer->_coordinate.y;
			std::cin.ignore(255, '\n');
			std::cin.get();*/
			ResetAIData();
			return false;
		}
		else
		{
			while (1)
			{
				if (STATE != TRY_BACK)
					CopyCoordinate(temp_coordinate, last_move);

				if (hits == MAX_HIT)
				{
					ClearStates();
					ResetAIData();
					//MAX_HIT--;
					break;
				}

				short status;


				if (diff != Easy && STATE == TRYSIDES)
				{
					if (!SetDirections(orientation, direction, direction_states))
					{
						ClearStates();
						ResetAIData();
						return false;
					}
				}

				if (orientation)
				{
					status = HorizontalAttack(human, computer, direction, temp_coordinate);
				}
				else
				{
					status = VerticalAttack(human, computer, direction, temp_coordinate);
				}

				//human->_board.PrintBoard();

				if (status == AIWIN)
				{
					ClearStates();
					ResetAIData();
					return true;
				}
				else if (status == ONE_MORE_ATTACK)
				{
					
					CopyCoordinate(last_move, temp_coordinate);
					(STATE == TRYSIDES) ? STATE++ : false;
					hits++; 
					/*std::cout << "Hit: " << temp_coordinate.x << ' ' << temp_coordinate.y;
					std::cin.ignore(255, '\n');
					std::cin.get();*/
					if (sound)
					{
						SoundEffects(1);
						Sleep(500);
					}
					continue;
				}
				else
				{
					/*std::cout << "Missed: " << temp_coordinate.x << ' ' << temp_coordinate.y;
					std::cin.ignore(255, '\n');
					std::cin.get();*/
					if (STATE == TRYSIDES)
					{
						if (diff == Easy)
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

							if (tries == MAX_TRY)
							{
								ResetAIData();
								return false;
							}
						}

						if (status == NEXT_TURN_OPPOSITE_DIRECTION)
						{
							//ClearStates(direction_states);
							return false;
						}
						continue;
					}
					else if (STATE == ATTACK_AGAIN)
					{
						GoBack(orientation, direction, hits + 1, temp_coordinate);

						if (!CheckCoordinates(human->_board, temp_coordinate))
						{
							ClearStates();
							ResetAIData();

							if (status == NEXT_TURN_OPPOSITE_DIRECTION)
							{
								return false;
							}
							continue;
						}

						GoBack(orientation, direction, -1, temp_coordinate);

						STATE++;

						direction = (direction) ? false : true;

						if (status == NEXT_TURN_OPPOSITE_DIRECTION)
						{
							return false;
						}
						continue;
					}
					else
					{
						ResetAIData();
						ClearStates();
						return false;
					}
				}
			}
		}
	}
}