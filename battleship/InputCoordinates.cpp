#include <iostream>
#include "Player.h"
#include <cstring>

void GetOrientation(char& orientation)
{
	do
	{
		std::cout << "Orientation: ";
		std::cin >> orientation;
		orientation = tolower(orientation);
	} while (orientation != 'h' && orientation != 'v');
}


void GetCoordinates(Coordinate & coordinate)
{
	char cx, cy;
	do
	{
		std::cout << "x (0 - 9) : ";
		std::cin >> cx;
	} while (int(cx) < 48 || int(cx) > 57);

	do
	{
		std::cout << "y (0 - 9) : ";
		std::cin >> cy;
	} while (int(cy) < 48 || int(cy) > 57);

	coordinate.x = int(cx) - 48;
	coordinate.y = int(cy) - 48;
}

void GetCoordinatesWithMouse(Coordinate & coordinate)
{
	return;
}