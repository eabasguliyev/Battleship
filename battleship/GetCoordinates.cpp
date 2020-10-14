#include <iostream>


void GetCoordinates(int& x, int& y)
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


	x = int(cx) - 48;
	y = int(cy) - 48;

}

void GetCoordinatesWithMouse(int& x, int& y)
{
	return;
}