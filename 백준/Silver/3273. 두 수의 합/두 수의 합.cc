#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, x;
	int cnt{ 0 };

	std::cin >> n;

	std::vector<int> arr;
	arr.reserve(n);

	for (int i = 0; i < n; ++i)
	{
		int temp;
		std::cin >> temp;

		arr.push_back(temp);
	}

	std::cin >> x;

	std::sort(arr.begin(), arr.end());

	int left{ 0 };
	int right{ n - 1 };

	while (left < right)
	{
		int sum{ arr[left] + arr[right] };

		if (sum == x)
		{
			++cnt;

			++left;
			--right;
		}
		else if (sum < x)
		{
			++left;
		}
		else
		{
			--right;
		}
	}

	std::cout << cnt;
}