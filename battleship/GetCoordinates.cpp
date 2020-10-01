#include <iostream>


void GetCoordinates(int& x, int& y)
{
	do
	{
		std::cout << "x (0 - 9) : ";
		std::cin >> x;
	} while (x < 0 || x > 9);

	do
	{
		std::cout << "y (0 - 9) : ";
		std::cin >> y;
	} while (y < 0 || y > 9);
}