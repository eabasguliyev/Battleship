#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Declarations.h"
#include <conio.h>

void SoundEffects(short id)
{
	switch (id)
	{
	case MISS_SOUND:
	{
		PlaySound(L"explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
	}break;
	case HIT_SOUND:
	{
		PlaySound(L"explosion2.wav", NULL, SND_FILENAME | SND_ASYNC);
	}break;
	default:
		break;
	}
}

short SoundSettings(bool inputDevices)
{

	system("CLS");

	int size = 3;
	char** options = new char* [size];
	options[0] = _strdup("On");
	options[1] = _strdup("Off");
	options[2] = _strdup("Back");

	if (inputDevices)
		return MenuInputWithMouse(options, size);
	else
		return MenuInputWithKeyboard(options, size);
}