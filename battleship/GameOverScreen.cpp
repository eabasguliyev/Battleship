#include <iostream>
#include "Declarations.h"
#include <conio.h>




bool GameOverScreen()
{

	short selected = 1;

	system("CLS");

	int size = 2;
	char** options = new char* [size];
	options[0] = _strdup("1. Rematch");
	options[1] = _strdup("2. Main Menu");

	ControlMenu(options, size, selected);

	return (selected == 1) ? true : false;
}