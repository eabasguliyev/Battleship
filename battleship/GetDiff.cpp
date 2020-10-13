#include <iostream>
#include "Declarations.h"
#include <conio.h>

short GetDiff(bool inputDevices)
{

	system("CLS");

	int size = 4;
	char** options = new char* [size];

	options[0] = _strdup("Very Easy");
	options[1] = _strdup("Easy");
	options[2] = _strdup("Normal");
	options[3] = _strdup("Hard");

	if (inputDevices)
		return MenuInputWithMouse(options, size);
	else
		return MenuInputWithKeyboard(options, size);
}