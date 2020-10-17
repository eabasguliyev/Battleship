#include <iostream>

void Wait()
{
	char* buff = new char[255];

	if (buff)
	{
		std::cout << "Press enter to continue";
		std::cin.getline(buff, 255);

		if (strcmp(buff, "") == 0)
		{
			std::cin.get();
		}
		delete[] buff;
	}
}