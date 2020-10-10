#include <iostream>
#include "Declarations.h"
#include <conio.h>
#include "Settings.h"


void SetChanges(short status, bool &change)
{
	if (status != 3)
	{
		change = (status == 1) ? true : false;
	}
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

void GameSettings(Settings & GS)
{

	while (1)
	{
		short selected = GameSettingsScreen(GS.inputDevices);
		switch (selected)
		{
		case 1:
		{
			short status = GameModeScreen(GS.inputDevices);
			SetChanges(status, GS.gameMode);
		}break;
		case 2:
		{
			short status = SoundSettings(GS.inputDevices);
			SetChanges(status, GS.sound);
		}break;
		case 3:
		{
			short status = InputDevicesSettings(GS.inputDevices);
			SetChanges(status, GS.inputDevices);
		}break;
		case 4:
		{
			return;
		}break;
		}
	}
}