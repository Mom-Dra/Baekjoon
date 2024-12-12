#include <iostream>

int main()
{
	int x, n;
	std::cin >> x >> n;

	int total{ 0 };

	for (int i{ 0 }; i < n; ++i)
	{
		int price, count;
		std::cin >> price >> count;

		total += price * count;
	}

	std::cout << (total == x ? "Yes" : "No");

	return 0;
}