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
			hits++;
			if (orientation)
			{
				temp_coordinate.y = (direction) ? (temp_coordinate.y - hits) : (temp_coordinate.y + hits);
			}
			else
			{
				temp_coordinate.x = (direction) ? (temp_coordinate.x - hits) : (temp_coordinate.x + hits);
			}
			if (CheckCoordinates(human->_board, temp_coordinate))
				STATE++;
			ResetData(STATE, last_move, tries, hits, orientation, direction);
			return;
		}
		else
		{
			if (status == 2)
			{
				STATE = 0;
				last_move.x = 0;
				last_move.y = 0;
				tries = 0;
				hits = 0;
				orientation = false;
				direction = false;
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