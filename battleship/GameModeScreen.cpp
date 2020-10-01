#include <iostream>
#include "Declarations.h"
#include <conio.h>


int GameModeScreen()
{
	
	short selected = 1;
	
	system("CLS");

	int size = 2;
	char** options = new char*[size];
	options[0] = _strdup("1. Singleplayer");
	options[1] = _strdup("2. Multiplayer");

	ControlMenu(options, size, selected);
	return selected;
}