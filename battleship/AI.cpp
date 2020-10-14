#include <time.h>
#include "Player.h"
#include "Declarations.h"
#include "Settings.h"

static int MAX_HIT = 5;
static int MIN_HIT = 2;
static char direction_states = 0;
static int STATE = 0;
static int hits = 0;
static short tries = 0;
static bool diagonal = true;
static bool best = true;
static Directions directions;

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

//state 1
// 0  AI_WIN true
// 1  one more attack, state 2.
// 2  next turn, coo is opposite direction
// 3  try again, coo is oppsoite direction

//state 2
// 0 ai win true
// 1 one more attack
// 2 next turn, state 3 opposite direct
// 3 try again, state 3 opposite direct


int GetStatusCode(Player* human, Player* computer, Coordinate& last_coo)
{
	if (CheckCoordinates(human->_board.board, last_coo))
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

bool CheckSides(int ** board, Coordinate coo, Directions directions)
{
	if (directions.orientation)
	{
		if (directions.direction)
			coo.y++;
		else
			coo.y--;
	}
	else
	{
		if (directions.direction)
			coo.x++;
		else
			coo.x--;
	}

	return CheckCoordinates(board, coo, true, true, directions.orientation, directions.direction);
}

int Attack(Player* human, Player* computer, Coordinate& last_coo, Directions directions)
{
	if (directions.orientation)
	{
		if (directions.direction)
			last_coo.y++;
		else
			last_coo.y--;

		if (last_coo.y < 0 || last_coo.y > 9)
			return 3;
	}
	else
	{
		if (directions.direction)
			last_coo.x++;
		else
			last_coo.x--;

		if (last_coo.x < 0 || last_coo.x > 9)
			return 3;
	}

	return GetStatusCode(human, computer, last_coo);
}

void ResetAIData(bool gameOver)
{
	if (gameOver)
	{
		MAX_HIT = 5;
		MIN_HIT = 2;
		diagonal = true;
		best = true;
	}
	STATE = 0;
	tries = 0;
	hits = 0;
	directions.orientation = false;
	directions.direction = false;
}

bool CheckState(int state, char direction_states);

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
	direction_states >>= 4;
}

void SetState(int state, char & direction_states)
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

bool CheckState(int state, char direction_states)
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


bool CheckMiniBlockOnBoard(int ** board, short min_hit, Coordinate coo, char direction_states)
{
	short hit = 1;
	short i = 0;
	short j = 0;
	bool flag = false;
	while (i < 4)
	{
		Coordinate current_coo = coo;
		while (hit < min_hit)
		{
			if (i == 3)
			{
				current_coo.y++;
				if (current_coo.y > 9)
					break;
			}
			else if (i == 2)
			{
				current_coo.y--;
				if (current_coo.y < 0)
					break;
			}
			else if (i == 1)
			{
				current_coo.x++;
				if (current_coo.x > 9)
					break;
			}
			else
			{
				current_coo.x--;
				if (current_coo.x < 0)
					break;
			}

			if (board[current_coo.x][current_coo.y] == 1 || board[current_coo.x][current_coo.y] == -1)
			{
				break;
			}
			hit++;
		}
		i++;
		if (i == 2 || i == 4)
		{
			if (min_hit > hit)
			{
				SetState(i - 1, direction_states);
				SetState(i, direction_states);
			}
			else
			{
				flag = true;
			}
			hit = 1;
		}
	}

	//std::cout << std::bitset<8>(direction_states) << std::endl;
	return flag;
}

bool SetDirections(Directions & directions,  char & direction_states)
{
	if (!RemainingDirections(direction_states))
	{
		ClearStates();
		return false;
	}

	while (true)
	{
		short state = rand() % 4 + 1;

		short status = CheckState(state, direction_states);

		if (status == 1)
		{
			continue;
		}

		if (state == UP || state == DOWN)
		directions.orientation = false;
		else
		directions.orientation = true;

		if (state == UP || state == LEFT)
		directions.direction = false;
		else
		directions.direction = true;

		SetState(state, direction_states);
		return true;
	}
}

void GoBack(Directions directions, short offset, Coordinate& coo)
{
	if (directions.orientation)
	{
		coo.y = (directions.direction) ? (coo.y - offset) : (coo.y + offset);
	}
	else
	{
		coo.x = (directions.direction) ? (coo.x - offset) : (coo.x + offset);
	}
}


short GetMinBlock(int** board)
{
	int min = 0;
	int counter = 0;

	for (size_t i = 2; i < 7; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			for (size_t k = 0; k < 10; k++)
			{
				if (board[j][k] == i)
				{
					counter++;
				}
			}
		}

		if (counter != 0)
		{
			return counter;
		}
	}
}

short GetMaxBlock(int** board)
{
	int max = 0;
	int counter = 0;

	for (size_t i = 2; i < 7; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			for (size_t k = 0; k < 10; k++)
			{
				if (board[j][k] == i)
				{
					counter++;
				}
			}
		}

		if (counter > max)
		{
			max = counter;
		}
		counter = 0;
	}

	return max;
}


bool CheckBestCoordinates(int** board);

short evenNumber()
{
	while (true)
	{
		int num = rand() % 11;
		if (num % 2 == 0)
			return num;
	}
}
bool GetBestCoordinate(int** board, Coordinate & coordinate)
{
	Coordinate coo;

	if (!CheckBestCoordinates(board))
	{
		return false;
	}

	while (true)
	{
		int x = evenNumber();
		int y = evenNumber();

		coo.x = (x > 5) ? x - 1 : x;
		coo.y = (y > 5) ? y - 1 : y;

		if (CheckCoordinates(board, coo, true))
		{
			coordinate.x = coo.x;
			coordinate.y = coo.y;
			return true;
		}
	}
}
bool CheckBestCoordinates(int** board)
{
	int x= 0, y = 0;
	Coordinate coo;
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t i = 0; i < 6; i++)
		{
			coo.x = x;
			coo.y = y;

			if(CheckCoordinates(board, coo, true))
			{
				return true;
			}
			if (y == 4)
			{
				y++;
			}
			else
			{
				y += 2;
			}
		}
		if (x == 4)
		{
			x++;
		}
		else
		{
			x += 2;
		}
		y = 0;
	}

	return false;
}

bool CheckDiagonalSpaces(int** board)
{
	Coordinate coo;
	for (size_t i = 0; i < 10; i++)
	{

		if (board[i][i] == 0)
		{
			coo.x = i;
			coo.y = i;
		}
		else if (board[i][9 - i] == 0)
		{
			coo.x = i;
			coo.y = 9 - i;
		}
		else
		{
			continue;
		}

		if (CheckCoordinates(board, coo, true))
		{
			return true;
		}
	}
	return false;
}

bool RandomCoordinateOnDiagonal(int ** board, Coordinate &coordinate)
{
	Coordinate rand_coo;

	if (!CheckDiagonalSpaces(board))
	{
		return false;
	}
	while (true)
	{
		short rand_int = rand() % 10;
		bool lr = rand() % 2;

		rand_coo.x = rand_int;
		rand_coo.y = (lr) ? rand_int : 9 - rand_int;

		if (CheckCoordinates(board, rand_coo, true))
		{
			coordinate.x = rand_coo.x;
			coordinate.y = rand_coo.y;
			return true;
		}
	}
	
}
const int MAX_TRY = 4;
static Coordinate last_move;
static Coordinate current_coordinate;
static char samesized_ships = 0;

enum Method
{
	Best_Coordinates = 1, Diagonal, Random
};
short GetMethod(int size)
{
	while (true)
	{
		short rnd = rand() % size;

		if ((rnd == Best_Coordinates && best) || (rnd == Diagonal && diagonal) || (rnd == Random))
		{
			return rnd;
		}
	}
}
bool  AI(Player* human, Player* computer, short diff, bool sound)
{
	while (1)
	{

		if (STATE == FIRST_ATACK)
		{
			if (diff >= Normal)
			{
				short method = GetMethod(4);
				if (method == Best_Coordinates && diff == Hard)
				{
					if (!GetBestCoordinate(human->_board.board, computer->_coordinate))
					{
						best = false;
					}
				}
				else if (method == Diagonal)
				{
					if (!RandomCoordinateOnDiagonal(human->_board.board, computer->_coordinate))
					{
						diagonal = false;
					}
				}
				else if (method == Random)
				{
					RandomCoordinate(human->_board.board, computer->_coordinate);
				}
				else
				{
					continue;
				}

				ClearStates();
				if (!CheckMiniBlockOnBoard(human->_board.board, MIN_HIT, computer->_coordinate, direction_states))
				{
					ClearStates();
					continue;
				}
			}
			else
			{
				RandomCoordinate(human->_board.board, computer->_coordinate);
			}
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
					Sleep(1000);
				}
				
				continue;
			}
			ResetAIData(false);
			return false;
		}
		else
		{
			while (1)
			{
				if (STATE != TRY_BACK)
					CopyCoordinate(current_coordinate, last_move);

				if (hits == MAX_HIT)
				{
					MAX_HIT = GetMaxBlock(human->_board.board);
					ClearStates();
					ResetAIData(false);
					break;
				}

				short status;

				if (STATE == TRYSIDES && diff != Easy)
				{
					if (!SetDirections(directions, direction_states))
					{
						ClearStates();
						ResetAIData(false);
						return false;
					}
					if (!CheckSides(human->_board.board, current_coordinate, directions))
					{
						continue;
					}
					
				}
				
				status = Attack(human, computer, current_coordinate, directions);
				if ((status == ONE_MORE_ATTACK || status == AIWIN ) && sound)
				{
					SoundEffects(1);
					Sleep(1000);
				}

				if (status == AIWIN)
				{
					ClearStates();
					ResetAIData(true);
					return true;
				}
				else if (status == ONE_MORE_ATTACK)
				{
					
					CopyCoordinate(last_move, current_coordinate);
					(STATE == TRYSIDES) ? STATE++ : false;
					hits++;
					continue;
				}
				else
				{
					if (STATE == TRYSIDES)
					{
						if (diff == Easy)
						{
							if (directions.direction)
							{
								directions.direction = false;
								directions.orientation = true;
							}
							else
							{
								directions.direction = true;
							}

							tries++;

							if (tries == MAX_TRY)
							{
								ResetAIData(false);
								return false;
							}
						}

						if (status == NEXT_TURN_OPPOSITE_DIRECTION)
						{
							return false;
						}
						continue;
					}
					else if (STATE == ATTACK_AGAIN)
					{
						GoBack(directions, hits + 1, current_coordinate);

						if (!CheckCoordinates(human->_board.board, current_coordinate, true, true, directions.orientation, !directions.direction))
						{
							if (hits == MIN_HIT)
							{
								MIN_HIT = GetMinBlock(human->_board.board);
							}
							ClearStates();
							ResetAIData(false);

							if (status == NEXT_TURN_OPPOSITE_DIRECTION)
							{
								return false;
							}
							break;
						}

						GoBack(directions, -1, current_coordinate);

						STATE++;

						directions.direction = (directions.direction) ? false : true;

						if (status == NEXT_TURN_OPPOSITE_DIRECTION)
						{
							return false;
						}
						continue;
					}
					else
					{
						if (hits == MIN_HIT)
						{
							MIN_HIT = GetMinBlock(human->_board.board);
						}
						ResetAIData(false);
						ClearStates();
						if (status == NEXT_TURN_OPPOSITE_DIRECTION)
							return false;
						break;
					}
				}
			}
		}
	}
}