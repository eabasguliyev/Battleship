#include <iostream>
#include "Declarations.h"
#include <conio.h>


short InputDevicesSettings(bool inputDevices)
{

	system("CLS");

	int size = 3;
	char** options = new char* [size];
	options[0] = _strdup("Mouse");
	options[1] = _strdup("Keyboard");
	options[2] = _strdup("Back");

	if (inputDevices)
		return MenuInputWithMouse(options, size);
	else
		return MenuInputWithKeyboard(options, size);
}