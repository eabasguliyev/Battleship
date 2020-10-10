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
		//mciSendString(L"play explosion.wav", NULL, 0, NULL);
	}break;
	case 1:
	{
		PlaySound(L"explosion2.wav", NULL, SND_FILENAME | SND_ASYNC);
	}break;
	default:
		break;
	}
}

