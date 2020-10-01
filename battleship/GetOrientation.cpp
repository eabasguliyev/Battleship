#include <iostream>
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