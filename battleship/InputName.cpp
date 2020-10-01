#include <iostream>

char* InputName()
{
	char* buf = new char[255];

	if (buf)
	{
		do
		{
			std::cin.getline(buf, 255);
		} while (strcmp(buf, "") == 0);

		return buf;
	}
	exit(1);
}