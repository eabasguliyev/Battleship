#include <iostream>
#include "Declarations.h"
#include <conio.h>


short GameModeScreen(bool inputDevices)
{
	
	system("CLS");

	int size = 3;
	char** options = new char*[size];
	options[0] = _strdup("Singleplayer");
	options[1] = _strdup("Multiplayer");
	options[2] = _strdup("Back");

	if (inputDevices)
		return MenuInputWithMouse(options, size);
	else
		return MenuInputWithKeyboard(options, size);
}