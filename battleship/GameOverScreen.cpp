#include <iostream>
#include "Declarations.h"
#include <conio.h>




bool GameOverScreen(bool inputDevices)
{

	system("CLS");

	int size = 2;
	char** options = new char* [size];
	options[0] = _strdup("Rematch");
	options[1] = _strdup("Main Menu");

	if (inputDevices)
		return (MenuInputWithMouse(options, size) == 1) ? true : false;
	else
		return (MenuInputWithKeyboard(options, size) == 1) ? true:false;
}