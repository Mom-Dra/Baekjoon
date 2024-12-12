#include <iostream>

int main()
{
	int byte;
	std::cin >> byte;

	for (int i{ 0 }; i < byte / 4; ++i)
	{
		std::cout << "long ";
	}

	std::cout << "int";

	return 0;
}