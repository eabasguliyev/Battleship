#include <iostream>
#include "Declarations.h"
#include <conio.h>

short GetDiff()
{

	short selected = 1;

	system("CLS");

	int size = 3;
	char** options = new char* [size];

	options[0] = _strdup("1. Amateur");
	options[1] = _strdup("2. Professional");
	options[2] = _strdup("3. Legend");

	ControlMenu(options, size, selected);

	return selected;
}