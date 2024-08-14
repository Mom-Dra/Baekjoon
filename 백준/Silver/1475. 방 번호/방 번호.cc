#include <iostream>
#include <array>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
    
	std::array<int, 9> arr = {};

	int num;
	int set{ 0 };
	std::cin >> num;

	while (num != 0)
	{
		int temp{ num % 10 };
		num /= 10;

		if (temp == 6 || temp == 9)
		{
			++arr[6];
			int cnt = arr[6] / 2 + arr[6] % 2;

			set = std::max(set, cnt);
		}
		else
		{
			++arr[temp];

			set = std::max(set, arr[temp]);
		}
	}

	std::cout << set;
}