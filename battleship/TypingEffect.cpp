#include <iostream>
#include <Windows.h>
#include "Declarations.h"
void TypingEffect(const char* text)
{
	for (size_t i = 0, length = strlen(text); i < length; i++)
	{
		std::cout << text[i];
		
		Sleep(50);
	}
	std::cout << std::endl;
}