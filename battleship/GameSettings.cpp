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