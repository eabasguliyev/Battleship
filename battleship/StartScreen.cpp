#include <iostream>
#include <Windows.h>

void TypingEffect(const char* text)
{
	for (size_t i = 0, length = strlen(text); i < length; i++)
	{
		std::cout << text[i];

		Sleep(50);
	}
	std::cout << std::endl;
}
void StartScreen()
{
	HANDLE hConsoleOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOUT, { 43, 12 });
	TypingEffect("Battleship game starting...");
	Sleep(1000);
}