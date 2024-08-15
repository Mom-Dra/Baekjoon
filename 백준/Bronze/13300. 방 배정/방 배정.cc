#include <iostream>
#include <array>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int k, n;
	int sum{ 0 };

	std::cin >> n >> k;

	std::array< std::array<int, 7>, 2> students = {};

	for (int i = 0; i < n; ++i)
	{
		int sex, grade;
		 
		std::cin >> sex >> grade;

		++students[sex][grade];
	}

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			int quotient = students[i][j] / k;
			int remainder = students[i][j] % k == 0 ? 0 : 1;

			sum += quotient + remainder;
		}
	}

	std::cout << sum;
}