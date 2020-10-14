#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include "Declarations.h"

void SoundEffects(short id)
{
	switch (id)
	{
	case EXPLODE:
	{
		PlaySound(L"explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
	}break;
	case 1:
	{
		PlaySound(L"explosion2.wav", NULL, SND_FILENAME | SND_ASYNC);
	}break;
	case 2:
	{
		PlaySound(L"key_press.wav", NULL, SND_FILENAME | SND_ASYNC);
	}break;
	default:
		break;
	}
}

