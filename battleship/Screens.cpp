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
		return (MenuInputWithKeyboard(options, size) == 1) ? true : false;
}

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


short GameSettingsScreen(bool inputDevices)
{

	system("CLS");

	int size = 4;
	char** options = new char* [size];
	options[0] = _strdup("Game Mode");
	options[1] = _strdup("Sound");
	options[2] = _strdup("Input Devices");
	options[3] = _strdup("Back");

	if (inputDevices)
		return MenuInputWithMouse(options, size);
	else
		return MenuInputWithKeyboard(options, size);
}


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