#include <iostream>
#include "Declarations.h"
#include <conio.h>


short MainScreen(bool inputDevices)
{

	system("CLS");

	int size = 4;
	char** options = new char* [size];
	options[0] = _strdup("Start");
	options[1] = _strdup("Game Settings");
	options[2] = _strdup("About");
	options[3] = _strdup("Exit");

	if (inputDevices)
		return MenuInputWithMouse(options, size);
	else
		return MenuInputWithKeyboard(options, size);
}